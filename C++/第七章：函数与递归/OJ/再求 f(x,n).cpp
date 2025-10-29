//# B2148 再求 f(x,n)
//
//## 题目描述
//
//已知
//
//$f(x,n)=\dfrac{x}{n+\dfrac{x}{(n-1)+\dfrac{x}{(n-2)+\dfrac{\vdots}{\cdots+\dfrac{x}{1+x}}}}}$。
//
//用递归函数求解。
//
//## 输入格式
//
//第一个数是 $x$ 的值，第二个数是 $n$ 的值。（$x$ 为**实数**，$n$ 为整数）
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
//1
//2
//```
//
//### 输出 #1
//
//```
//0.40
//```

#include <iostream>
#include <cstdio>

using namespace std;

double func(double x, int n)
{
    if(n == 1)
        return x * 1.0 / (1 + x);
    else
        return x * 1.0 / (n + func(x, n - 1));
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double ret = func(x, n);
    printf("%.2lf\n", ret);

    return 0;
}
