#include <iostream>
using namespace std;
#include <vector>
#include<iomanip>
int main()
{
    int cow, row;

    cin >> row >> cow;
    vector<vector<int>> arr(row, vector<int>(cow));
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < cow; k++)
            cin >> arr[j][k];
    }

    cin >> row >> cow;
    vector<vector<int>> brr(row, vector<int>(cow));
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < cow; k++)
            cin >> brr[j][k];
    }

    vector<vector<int>> ans(arr.size(), vector<int>(brr[0].size()));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr[0].size(); j++)
        {
            for (int z = 0; z < brr.size(); z++)
            {
                ans[i][j] += arr[i][z] * brr[z][j];
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr[0].size(); j++)
        {
            cout << setw(5) << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}