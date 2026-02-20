#include<iostream>
#include<thread>
using namespace std;
class thread_guard{
    thread& t;
    public:
        explicit thread_guard(thread& t_) : t(t_){}
        ~thread_guard(){
            if(t.joinable()){
                t.join();
            }
        }
        thread_guard(thread_guard const&) = delete;
        thread_guard& operator=(thread_guard const&) = delete;

};
struct func{
    int & state;
    func(int& s):state(s){}
    void operatpr(){
        for(int i=0;i<10;i++){
            ++state;
            cout<<"In thread:state="<<state<<endl;
        }
    }
};
void do_something_in_current_thread(){
    cout<<"in main thread : doing something..."<<endl;
}
int main(){
    int some_local_state=0;
    {
        func my_func(some_local_state);
        thread t(my_func);
        thread_guard g(t);
        do_something_in_current_thread();

    }
    cout<<"Final state : "<<some_local_state<<endl;
    return 0;
}