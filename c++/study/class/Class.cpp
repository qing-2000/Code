#include<iostream>
#include<cstdlib>
using namespace std;
class Box{
    public:
        double length,width,highth;
        double Boxarea(void);
       
};

double Box::Boxarea(void){
    return length*width*highth;
}
int main(){
    Box box1,box2;
    double V;
    box1.length=1.0,box1.width=2.0,box1.highth=3.0;
    V=box1.Boxarea();
    cout<<"box1的体积是"<<V<<endl;

    
    box2.length=4.0,box2.width=5.0,box2.highth=6.0;
    V=box2.Boxarea();
    cout<<"box2的体积是"<<V<<endl;
    system("pause");
    return 0;
}