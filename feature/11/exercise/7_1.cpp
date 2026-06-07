/*
实现简单线程池

ThreadPool p(4); // 指定四个工作线程
// 将任务在池中入队，并返回一个 std::future
auto f = pool.enqueue([](int life) {
    return meaning;
}, 42);
// 从 future 中获得执行结果
std::cout << f.get() << std::endl;

*/
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <iostream>
class ThreadPool {
public:
    //创建线程，分拣任务
    ThreadPool(size_t n) {
        for (size_t i = 0; i < n; ++i)
            /*
            lambda不是立即执行，所以不用在 lambda 后面加 ()。

            为什么捕获 [this]：工作线程要访问类的成员变量（比如任务队列 tasks、锁 mtx、条件变量 cv），
            用 [this] 就能在 lambda 里面直接使用这些成员，像用自己的一样。

            为什么不用 [&]：[&] 会捕获当前作用域里的所有局部变量，这里没有别的局部变量需要捕获，
            用 [this] 更明确——我只需要访问类成员，不碰别的东西。

            */
            workers.emplace_back([this] {
                while (true) {
                    /*
                    
                    std::function 是一个万能函数容器。可以往里面塞普通函数、lambda、可调用对象……在这里，
                    它的作用就是从队列里取出一个“任务”，然后直接 task() 执行。
                    后面塞任务时用了 tasks.emplace([p]{ (*p)(); })，
                    其实就是把一个小 lambda 存进队列，而这个 lambda 又被 std::function 装起来，等线程拿出来跑。

                    */
                    std::function<void()> task;
                    //限定锁的作用域。出了括号，锁就自动释放了。
                    {
                        std::unique_lock lk(mtx);
                        /*
                        条件变量的核心：工作线程如果没有活儿干（队列空），就睡在这儿。一旦有新任务或线程池要关闭（stop=true），
                        它就被唤醒继续干活。wait 的第二个参数就是“醒了之后还要检查的条件”，防止无意义的虚假唤醒。
                        */
                        cv.wait(lk, [this]{ return !tasks.empty() || stop; });
                        if (stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    
                    task();
                }
            });
    }

    template<class F, class... Args>
    
    auto enqueue(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {

        /*

        组件	                                    作用
        std::bind	            把“函数 + 参数”打包成一个无参可调用对象 void f() { return f(42); }
        std::packaged_task	    包裹这个无参对象，同时提供 future，以便把返回值传出去
        std::shared_ptr	        因为 packaged_task 不可拷贝，必须用智能指针让它能在队列里生存
        
        如果不这样写，你没法把“带参数、有返回值的函数”塞进一个只接受 void() 的队列。

        */
        
        using ret_t = decltype(f(args...));
        //打包ret_t类型的共享指针，绑定什么，格式化什么，看不懂
        auto p = std::make_shared<std::packaged_task<ret_t()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        //获取期待future
        std::future<ret_t> res = p->get_future();
        
        /*
        限定锁的作用域。出了括号，锁就自动释放了。
        这样可以在调用 cv.notify_one() 前把锁放了，避免被唤醒的线程又撞上锁——经典的条件变量用法。
        */

        {
            std::unique_lock lk(mtx);
            /*
            为什么不用 weak_ptr？
            因为任务必须保证在执行前 packaged_task 是活的，用 shared_ptr 能保持引用计数，任务队列持有它，
            就不会提前销毁。weak_ptr 无法直接执行，还要 lock() 成 shared_ptr，这里完全没必要。


            p 是一个 shared_ptr，指向 packaged_task 对象。
            (*p)() 就是调用这个 task 对象，让它执行所包装的任务，并把返回值存入 future
            */
            tasks.emplace([p]{ (*p)(); });
        }
        //叫醒一个，避免惊群
        cv.notify_one();
        return res;
    }

    ~ThreadPool() {
        //多线程共享的，修改它需要保护。
        {
            std::unique_lock lk(mtx);
            stop = true;
        }
        
        cv.notify_all();
        
        for (auto& w : workers) w.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;
    bool stop = false;
};

int main() {
    ThreadPool pool(4);
    auto f = pool.enqueue([](int meaning) { return meaning; }, 42);
    std::cout << f.get() << std::endl; // 输出 42
    return 0;
}