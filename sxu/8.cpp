#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

const double EPS = 1e-12;

double fixZero(double x) {
    return fabs(x) < EPS ? 0 : x;
}

int main() {
    int k;
    double a, b, c;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        double delta = b * b - 4 * a * c;
        double real = -b / (2 * a);
        if (delta >= 0) {
            double sqrt_delta = sqrt(delta) / (2 * a);
            double x1 = real + sqrt_delta;
            double x2 = real - sqrt_delta;
            x1 = fixZero(x1);
            x2 = fixZero(x2);
            if (fabs(x1 - x2) < EPS) {
                cout << fixed << setprecision(5) << "x1=x2=" << x1 << endl;
            } else {
                cout << fixed << setprecision(5) << "x1=" << x1 << ";x2=" << x2 << endl;
            }
        } else {
            double imag = fabs(sqrt(-delta) / (2 * a));
            real = fixZero(real);
            imag = fixZero(imag);
            cout << fixed << setprecision(5) << "x1=" << real << "+" << imag << "i;x2=" << real << "-" << imag << "i" << endl;
        }
    }
    return 0;
}
/*

缺少对0处理

#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<complex>//虚数
using namespace std;
int main(){
    int k;
    double a,b,c;
    cin>>k;
    vector<pair<double,double>> arr(k);
    vector<bool> brr(k,0);
    for(int i=0;i<k;i++){
        cin>>a>>b>>c;
        double temp=b*b-4*a*c;
        if(temp>=0){
            arr[i].first=-b/2/a;
            arr[i].second=sqrt(temp)/(2*a);
            brr[i]=1;
        }else{
            arr[i].first=-b/2/a;
            arr[i].second=sqrt(abs(temp))/(2*a);
        }
    }
    for(int i=0;i<k;i++){
        if(brr[i]){
            //如果是实数根
            double ans1,ans2;
            ans1=arr[i].first+arr[i].second;
            ans2=arr[i].first-arr[i].second;
            if(ans2==ans1){
                cout<<fixed<<setprecision(5)<<"x1=x2="<<ans1<<endl;
            }else{
                cout<<fixed<<setprecision(5)<<"x1="<<ans1<<";x2="<<ans2<<endl;
            }
        }else if(brr[i]==0){
            cout<<fixed<<setprecision(5)<<"x1="<<arr[i].first<<"+"<<arr[i].second<<"i;"<<"x2="<<arr[i].first<<"-"<<arr[i].second<<"i"<<endl;
        }
    }
    return 0;
}
    */