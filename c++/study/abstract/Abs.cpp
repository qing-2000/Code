#include<iostream>
using namespace std;
class Adder{
    //抽象保护total，但外部能通过接口获取total的值
    private:
        double total;
    public:
        double Total(void){
            return total;
        }
        void addt(double num){
            total+=num;
        }
};
int main(){
    Adder a;
    a.addt(10);
    cout<<a.Total();
    return 0;
}