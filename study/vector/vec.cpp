#include<iostream>
#include<vector>
using namespace std;
int main(){
    //创建整型容器
    vector<int> myVector(10,0);

    //添加元素
    myVector.push_back(7);
    myVector.push_back(9);

    cout<<"Vector中的内容是：";
    for(auto& num:myVector)cout<<num<<"\t";
    cout<<endl;

    
    //
    int x = myVector[10]; // 获取第11个元素
    int y = myVector.at(11); // 获取第12个元素
    cout<<"第11个元素："<<x<<endl;
    cout<<"第12个元素："<<y<<endl;

    //
    int size = myVector.size(); // 获取 vector 中的元素数量
    cout<<"容器中有"<<size<<"个元素."<<endl;
    
    
    
    //
    myVector.erase(myVector.begin() + 2); // 删除第三个元素
    cout<<"删除第二个元素后：";
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    cout<<endl;


    //
    myVector.clear(); // 清空 vector
    cout<<"容器有："<<myVector.size()<<"个元素.";
    
    return 0;
}