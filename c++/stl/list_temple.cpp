#include<iostream>
//双向列表
#include<list>
int main(){
    std::list<int> l;
    for(int i=0;i<20;i++){
        //push_front在列表前增加元素,pop同push
        l.push_back(i);
    }
    std::list<int>::iterator it;//list指针
    int k=2;
    //将一个队人寄次轮去当前位置为除2的倍数，偶次轮去除3的倍数，直至人数<=3
    while(l.size()>3){
        int num=1;
        //★★★
        for(it=l.begin();it!=l.end();it++){
            if(num++%k==0){
                it=l.erase(it);
            }
        }
        k==2?k=3:k=2;
    }
    
    if(!l.empty()){
        for(auto x=l.begin();x!=l.end();x++)std::cout<<*x<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"一共："<<l.size();
    return 0;
}