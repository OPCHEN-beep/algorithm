//# P1480 A/B Problem
//
//## 题目描述
//
//输入两个整数 $a,b$，输出它们的商。
//
//## 输入格式
//
//两行，第一行是被除数，第二行是除数。
//
//## 输出格式
//
//一行，商的整数部分。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10
//2
//```
//
//### 输出 #1
//
//```
//5
//```
//
//## 说明/提示
//
//$0\le a\le 10^{5000}$，$1\le b\le 10^9$。# P1480 A/B Problem
//
//## 题目描述
//
//输入两个整数 $a,b$，输出它们的商。
//
//## 输入格式
//
//两行，第一行是被除数，第二行是除数。
//
//## 输出格式
//
//一行，商的整数部分。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10
//2
//```
//
//### 输出 #1
//
//```
//5
//```
//
//## 说明/提示
//
//$0\le a\le 10^{5000}$，$1\le b\le 10^9$。

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

typedef long long LL;

int a[N], b, c[N];
int la, lb, lc;

//高精度除法的模版 - c = a / b
void sub(int c[], int a[], int b)
{
    LL t = 0;
    for(int i = la - 1; i >= 0; i--)
    {
        //计算当前的被除数
        t = t * 10 + a[i];
        c[i] = t / b;
        t %= b;
    }

    //处理前导0
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
    string x;
    cin >> x >> b;
    la = x.size();

    for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';

    //模拟除法的过程
    lc = la;
    sub(c, a, b);

    for(int i = lc - 1; i >= 0; i--) cout << c[i];

    return 0;
}
