
#include<iostream>
using namespace std;

class human {
public:
    virtual void toilet() = 0;
    virtual ~human() {}  // 添加虚析构函数
};

class man : public human {
public:
    void toilet() override { cout << "去男厕。"; }  // 添加override关键字
};

class woman : public human {
public:
    void toilet() override { cout << "去女厕。"; }  // 添加override关键字
};

void func(human* h) {  // 参数名改为h避免与类名冲突
    h->toilet();
}

int main() {
    man arr[4];  // 直接初始化数组
    woman brr[4];

    for (int i = 0; i < 4; i++) {
        cout << "对象" << i + 1 << ":";
        func(&arr[i]);
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        cout << "对象" << i + 1 << ":";
        func(&brr[i]);
        cout << endl;
    }
    return 0;  // 正常返回0
}
