#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class animals{
    public:
        string name;
        virtual void sound(void){ // 声明为虚函数以实现多态
        cout << "Some generic animal sound" << endl;
    }
};
class dog: public animals{
    public:
        dog(){
            name="dog";
        }
        void sound(void) override{
            cout<<"bark"<<endl;
        }
};
class cat:public animals{
    public:
        cat(){
            name="cat";
        }
        void sound(void) override{
            cout<<"miao"<<endl;
        }
};

int main(){
    dog d;
    cat c;
    
    cout<<"This is\t"<<d.name<<endl;
    cout<<"The voice is\t";
    d.sound();
    cout<<"This is\t"<<c.name<<endl;
    cout<<"The voice is\t";
    c.sound();
    cout << "============================" << endl;
    
    // 使用基类指针演示多态
    animals* animal[2];
    animal[0] = &d;
    animal[1] = &c;
    
    for(int i = 0; i < 2; i++) {
        cout << animal[i]->name << " says: ";
        animal[i]->sound();
    }
    return 0;
}