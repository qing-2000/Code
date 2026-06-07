/*
使用atomic实现互斥锁
*/
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>
class SpinLock {
public:
    void lock() {
        while (flag.exchange(true, std::memory_order_acquire));
    }
    void unlock() {
        flag.store(false, std::memory_order_release);
    }
    bool try_lock() {
        return !flag.exchange(true, std::memory_order_acquire);
    }
private:
    std::atomic<bool> flag{false};
};
class SpinLockGuard {
    SpinLock& lock;
public:
    explicit SpinLockGuard(SpinLock& l) : lock(l) { lock.lock(); }
    ~SpinLockGuard() { lock.unlock(); }
    // 禁止拷贝
    SpinLockGuard(const SpinLockGuard&) = delete;
    SpinLockGuard& operator=(const SpinLockGuard&) = delete;
};
SpinLock spin;
int counter = 0;  // 受保护资源

void increment(int n) {
    for (int i = 0; i < n; ++i) {
        SpinLockGuard guard(spin);  // 如果 SpinLock 符合 BasicLockable 要求
        ++counter;
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(increment, 100000);
    }
    for (auto& t : threads) t.join();
    std::cout << counter << std::endl;  // 400000
}