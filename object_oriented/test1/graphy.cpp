#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;
class graph{
    virtual float c() = 0;
    virtual float s() = 0;
	//virtual ~graph() {}
};
class circle :public graph {
	float r;
	
public :
	circle(float radius) { r = radius; }
	float c() override { return M_PI * r * r; };
	float s() override { return 2 * M_PI * r; };
};
int main() {
	circle a(1);
	cout << "面积：" << a.c() << endl;;
	cout<<"周长："<<a.s()<<endl;
	return -1;
}