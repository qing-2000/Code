#include <iostream>
#include <thread>
#include <csignal>
#include <vector>
#include <mutex>
std::once_flag flag;
void init()
{
    std::cout << "初始化已完成。。。" << std::endl;
}
void worker(int id)
{
    std::call_once(flag, init);
    std::cout << id << "is working" << std::endl;
}
void signal_handler(int sig)
{
    std::cout << "接收到信号: " << sig << std::endl;
    if (sig == SIGINT)//win处理ctrl+c中断
    { // SIGUSR1不适用于win
        std::cout << "处理用户自定义信号" << std::endl;
        std::exit(0);
    }
}
int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(worker, i);
    }
    for (auto &t : threads)
    {
        t.join();
    }
    std::signal(SIGINT, signal_handler);
    return 0;
}