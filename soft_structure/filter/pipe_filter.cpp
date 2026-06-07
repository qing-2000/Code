#include <iostream>            // 引入输入输出库，用于输出结果
#include <thread>              // 引入线程库，用于多线程操作
#include <mutex>               // 引入互斥锁库，用于线程同步
#include <condition_variable>  // 引入条件变量库，用于线程间的同步和通信
#include <queue>               // 引入队列库，用于存储数据

std::mutex mtx;              // 声明一个互斥锁，用于保护数据访问
std::condition_variable cv;  // 声明一个条件变量，用于线程间的通知
std::queue<std::string> data_queue;  // 声明一个字符串队列，用于存储要处理的数据

// 过滤A操作
void filterA() {
    std::unique_lock<std::mutex> lck(mtx);  // 锁住互斥锁，确保线程安全
    cv.wait(lck, [] { return !data_queue.empty(); });  // 等待队列中有数据
    std::string data = data_queue.front();  // 获取队列的第一个数据
    data_queue.pop();  // 移除队列中的第一个数据
    lck.unlock();  // 释放锁

    // 进行过滤操作，这里只是一个示例，实际过滤操作可以是任何你需要的操作
    for (char& c : data) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // 将小写字母转换为大写字母
        }
    }

    std::cout << "Filter A: " << data<<std::endl ;  // 输出过滤后的结果
}

// 过滤B操作
void filterB() {
    std::unique_lock<std::mutex> lck(mtx);  // 锁住互斥锁，确保线程安全
    cv.wait(lck, [] { return !data_queue.empty(); });  // 等待队列中有数据
    std::string data = data_queue.front();  // 获取队列的第一个数据
    data_queue.pop();  // 移除队列中的第一个数据
    lck.unlock();  // 释放锁

    // 进行过滤操作，这里只是一个示例，实际过滤操作可以是任何你需要的操作
    for (int i = 0; i < data.size(); i += 2) {
        data[i] = ' ';  // 将偶数位置的字符替换为空格
    }

    std::cout << "Filter B: " << data <<std::endl;  // 输出过滤后的结果
}

int main() {
    std::thread t1(filterA);  // 创建一个线程t1，用于执行filterA函数
    std::thread t2(filterB);  // 创建一个线程t2，用于执行filterB函数

    // 模拟数据输入
    {
        std::lock_guard<std::mutex> lck(mtx);  // 使用lock_guard自动加锁
        data_queue.push("hello");  // 向队列中推入数据"hello"
      
        data_queue.push("world");  // 向队列中推入数据"world"
    }
    cv.notify_all();  // 通知所有等待的线程队列中有数据

    t1.join();  // 等待线程t1执行完毕
    t2.join();  // 等待线程t2执行完毕

    return 0;  // 主函数结束
}
