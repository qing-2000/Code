#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
void classifyChars(const string& str, 
                   vector<int>& numbers,
                   vector<string>& letters,
                   vector<char>& symbols){
    
    string currentNum;
    string currentLetters;
    
    for(char c : str){
        if(isdigit(c)){
            currentNum += c;
            // 如果之前有累积的字母串，先存入
            if(!currentLetters.empty()){
                letters.push_back(currentLetters);
                currentLetters.clear();
            }
        }
        else if(isalpha(c)){
            currentLetters += c;
            // 如果之前有累积的数字串，先存入
            if(!currentNum.empty()){
                numbers.push_back(stoi(currentNum));
                currentNum.clear();
            }
        }
        else{
            // 特殊字符
            if(!isblank(c)){
                symbols.push_back(c);
            }
            // 处理之前累积的内容
            if(!currentNum.empty()){
                numbers.push_back(stoi(currentNum));
                currentNum.clear();
            }
            if(!currentLetters.empty()){
                letters.push_back(currentLetters);
                currentLetters.clear();
            }
        }
    }
    
    // 处理最后累积的内容
    if(!currentNum.empty()){
        numbers.push_back(stoi(currentNum));
    }
    if(!currentLetters.empty()){
        letters.push_back(currentLetters);
    }
}
int main(){
    string str;
    vector<int> a;
    vector<char> alphas; 
    vector<string> c;
    getline(cin,str);
    classifyChars(str,a,c,alphas);
    cout<<"字符串中的数字：";
    for(int i :a)cout<<i<<" ";
    cout<<endl;
    cout<<"字符串中的字符: ";
    for(auto i :c)cout<<i<<" ";
    cout<<endl;
    cout<<"字符串中的字符: ";
    for(auto i :alphas)cout<<i<<" ";
    return 0;
}