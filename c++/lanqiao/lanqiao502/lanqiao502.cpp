#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int sum, score, temp1 = 0, temp2 = 0;
    float pass, outstanding;
    cin >> sum;
    for (int i = 0; i < sum; i++) {
        cin >> score;
        if (score >= 60) {
            temp1++;
        }
        if (score >= 85) {
            temp2 ++;
        }
    }
    pass = round(temp1 *100/ sum);//round四舍五入
    outstanding = round(temp2*100 / sum);
    printf("%.0f%%\n", pass);//%%输出%，.0f输出0位小数的浮点数
    printf("%.0f%%", outstanding);
    return 0;
}