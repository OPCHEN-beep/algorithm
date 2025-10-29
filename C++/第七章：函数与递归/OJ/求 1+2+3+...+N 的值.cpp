//# B2142 求 1+2+3+...+N 的值
//
//## 题目描述
//
//用递归的方法求 $1+2+3+$ …… $+N$ 的值。
//
//## 输入格式
//
//输入 $N$。
//
//## 输出格式
//
//输出和。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//```
//
//### 输出 #1
//
//```
//15
//```
//
//## 说明/提示
//
//$N\le 200$

#include <iostream>
using namespace std;

int sum(int n)
{
    if(n == 1)
        return 1;
    else
        return n + sum(n - 1);
}

int main()
{
    int n = 0;
    cin >> n;
    cout << sum(n) << endl;

    return 0;
}
