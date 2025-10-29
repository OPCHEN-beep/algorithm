//# B2143 进制转换
//
//## 题目描述
//
//用递归算法将一个十进制整数 $X$（$1 \le X \le 10^9$）转换成任意进制数 $M$（$2\le M\le16$，$M$ 为整数）。
//
//## 输入格式
//
//一行两个数，第一个十进制整数 $X$，第二个为进制 $M$。
//
//## 输出格式
//
//输出结果。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//31 16
//```
//
//### 输出 #1
//
//```
//1F
//```
//
//## 说明/提示
//
//**样例解释**。
//
//将十进制 $31$ 转化为十六进制数。

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s = "0123456789ABCDEF";

void XToM(int x, int m)
{
    if(x >= m)
        XToM(x / m, m);
    cout << s[x % m];
}
    
    
int main()
{
    int x = 0;
    int m = 0;
    cin >> x >> m;
    XToM(x, m);
    

    return 0;
}
