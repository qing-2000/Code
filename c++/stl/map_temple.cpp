#include<iostream>
#include<string>
#include<map>//自动升序
#include<functional>
void P(std::map<std::string,int> m){
    if(!m.empty()){
        for(std::map<std::string,int>::iterator x=m.begin();x!=m.end();x++)std::cout<< x->first <<" : "<< x->second <<" ";
        /*
            c++11特性:
            for (auto &p : m) {
                std::cout << p.first << " : " << p.second << std::endl;
            }
        */
    }
    else{
        std::cout<<"M的元素有："<<m.size()<<"个。";
    }
    std::cout<<std::endl;
}
//降序
bool myCompare(const std::string& a, const std::string& b) {
    return a < b;
}
int main(){
    std::map<std::string,int> M;
    std::map<std::string,int>::iterator it;
    M.insert({"sbwjx",250}); //或者M.insert(std::make_pair("sbwjx", 250));或M["Alice"] = 30;进行插入
    P(M);
    M.erase("sbwjx");
    P(M);
    M.clear();
    std::cout<<M.count("sbwjx");//是否存在，返回01
    std::map<std::string, int, std::function<bool(const std::string&, const std::string&) >> M(myCompare);
    return 0;
}