//# B2109 统计数字字符个数
//
//## 题目描述
//
//输入一行字符，统计出其中数字字符的个数。
//
//## 输入格式
//
//一行字符串，总长度不超过 $255$。
//
//## 输出格式
//
//输出为 $1$ 行，输出字符串里面数字字符的个数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//Today is 2021-03-27
//```
//
//### 输出 #1
//
//```
//8
//```

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 266;
char arr[N];

int main()
{
    fgets(arr, N, stdin);
    int i = 0;
    int c = 0;
    while(arr[i] != '\n')
    {
        if(arr[i] >= '0' && arr[i] <= '9')
        {
            c++;
        }
        i++;
    }
    cout << c << endl;

    return 0;
}
