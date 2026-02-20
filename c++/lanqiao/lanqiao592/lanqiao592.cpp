#include <iostream>
using namespace std;
int main()
{
    int sum = 0, temp;
    for (int i = 1; i < 2021; i++) {
        for (int j = i; j > 0; ) {

            temp = j % 10;
            if (temp == 2)
                sum++;
            j /= 10;
        }
    }
    cout << sum;
    return 0;
}