#include<iostream>
#include<set>//元素唯一，自动升序的数组
#include<algorithm>//求交，并，差，对称差集所需
void P(std::set<int> A){
    std::set<int>::iterator it;
    for(it=A.begin();it!=A.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";
}
int main(){
    std::set<int> A,B,C;
    int i=0;
    while(i<20){
        //insert进，erase删除
        if(i%2==0)A.insert(i);
        else B.insert(i);
        i++;
    }
    std::set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.begin()));//并集
    /*
        同一个模版
        std::set_intersection：求交集
        std::set_union：求并集
        std::set_difference：求差集
        std::set_symmetric_difference：求对称差集
    */
    P(A);
    P(B);
    P(C);
    //find,lower_bound() '<=' ,upper_bound() '>' 返回迭代器不能直接输出
    std::cout << *C.find(2);
    /*
        clear()清空
        empty()判断空

    */
    return 0;
}