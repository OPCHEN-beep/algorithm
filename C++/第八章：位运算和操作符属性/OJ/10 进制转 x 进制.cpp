//# B3619 10 进制转 x 进制
//
//## 题目描述
//
//给定一个十进制整数 $n$ 和一个小整数 $x$。将整数 $n$ 转为 $x$ 进制。对于超过十进制的数码，用 `A`，`B` ... 表示。
//
//## 输入格式
//
//第一行一个整数 $n$；
//
//第二行一个整数 $x$。
//
//## 输出格式
//
//输出仅包含一个整数，表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1000
//2
//```
//
//### 输出 #1
//
//```
//1111101000
//```
//
//## 说明/提示
//
//【数据规模和约定】  
//保证 $n$ 不超过 $10^9$，$x$ 不超过 $36$。

#include <iostream>
#include <string>
using namespace std;

string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void print(int n, int x)
{
    if(n >= x)
    {
        print(n / x, x);
    }
    cout << s[n % x];
}

int main()
{
    int n = 0;
    int x = 0;
    cin >> n >> x;
    print(n, x);

    return 0;
}
