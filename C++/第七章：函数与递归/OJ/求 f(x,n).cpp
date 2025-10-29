//# B2147 求 f(x,n)
//
//## 题目描述
//
//已知 $f(x,n)=\sqrt{n+\sqrt{(n-1)+\sqrt{(n-2)+\sqrt{...+2+\sqrt{1+x}}}}}$。
//
//计算 $f$ 的值。
//
//## 输入格式
//
//输入 $x$ 和 $n$。
//
//## 输出格式
//
//函数值，保留两位小数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4.2 10
//```
//
//### 输出 #1
//
//```
//3.68
//```
//
//## 说明/提示
//
//#### 数据范围
//
//对于 $100\%$ 的数据，$1 \le x,n \le 10$。

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double func(int x, int n)
{
    if(n == 1)
        return sqrt(1 + x);
    else
        return sqrt(n + func(x, n - 1));
}

int main()
{
    int x, n;
    cin >> x >> n;

    double ret = func(x, n);
    printf("%.2lf\n", ret);

    return 0;
}
