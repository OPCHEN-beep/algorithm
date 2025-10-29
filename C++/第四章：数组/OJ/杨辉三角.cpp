//# P5732 【深基5.习7】杨辉三角
//
//## 题目描述
//
//给出 $n(1\le n\le20)$，输出杨辉三角的前 $n$ 行。
//
//如果你不知道什么是杨辉三角，可以观察样例找找规律。
//
//## 输入格式
//
//无
//
//## 输出格式
//
//无
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//6
//```
//
//### 输出 #1
//
//```
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
//```

#include <iostream>
#include <cstdio>
using namespace std;

int arr[25][25];


int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                arr[i][j] = 1;
            }
            if(i == j)
            {
                arr[i][j] = 1;
            }
            if(i >= 2 && j >= 1)
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
} 
