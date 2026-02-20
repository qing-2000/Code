#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<cmath>
std::vector<int> arr;
void rand_num(int num,int min,int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min,max);
    arr.clear();
    for(int i=0;i<num;i++){
        arr.push_back(dis(gen));
    }
}
bool myRule(int a,int b){
    return a>b;
}
void ascending_order(std::vector<int> arr){
    sort(arr.begin(),arr.end());
    for(auto &a : arr){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
}
void desceding_order(std::vector<int> arr){
    sort(arr.begin(),arr.end(),myRule);
    for(auto &a : arr){
        std::cout<<a<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    std::cout<<"输入要生成多少个随机数的数量：";
    int num;
    std::cin>>num;
    std::cout<<std::endl;
    std::cout<<"输入要生成多少个随机数的范围（小，大）：";
    int mi,ma;
    std::cin>>mi>>ma;
    std::cout<<std::endl;
    rand_num(num,mi,ma);

    while(1){
        std::cout<<"选择1升序..."<<std::endl;
        std::cout<<"选择2降序..."<<std::endl;

        int option=-1;
        std::cout<<"请输入选择："<<std::endl;
        std::cin>>option;
        switch(option){
            case 1:
                ascending_order(arr);
                break;                              //防止case穿透
            case 2:
                desceding_order(arr);
                break;
            default:
                break;
        }

        if(option != 1 && option != 2)break;             //不可写为||
    }
    return 0;
}