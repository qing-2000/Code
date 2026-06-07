#include<iostream>
#include<queue>
int main(){
    std::queue<char> q;
    std::cout<<"提示：输入。时停止...";
    char ch;
    while(1){
        
        std::cin>>ch;
        if(ch!=':'){
            q.push(ch);
        }
        else{
            std::cout<<"输入的内容为：";
            while(q.size()!=0){

                //q.back返回队尾元素
                std::cout<<q.front();
                q.pop();
            }
            break;
        }
    }
    return 0;
}