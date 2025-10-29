//# B2129 最大数 max(x,y,z)
//
//## 题目描述
//
//已知：
//
//$m=\dfrac{\max(a,b,c)}{\max(a+b,b,c) \times \max(a,b,b+c)}$
//
//输入三个整数 $a$，$b$，$c$，求 $m$。
//
//把求三个数的最大数 $\max(x,y,z)$ 分别定义成函数和过程来做。
//
//## 输入格式
//
//输入只有一个行三个整数，分别为 $a, b, c$。
//
//## 输出格式
//
//输出一行一个小数，为答案，保留三位小数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1 2 3
//```
//
//### 输出 #1
//
//```
//0.200
//```
//
//## 说明/提示
//
//### 数据规模与约定
//
//对于全部的测试点，保证 $|a|,|b|,|c| \leq 50$。换句话说，$a,b,c$ 都在 $-50$ 到 $50$ 之间。
//
//测试数据保证，分式的分母不为 $0$。

#include <iostream>
using namespace std;


int max(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else if(c >= a && c >= b)
        return c;
}

int main()
{
    ios::sync_with_stdio(false); //取消给C语?输?输出缓冲区的同步
    cin.tie(0); //取消了cin和cout的绑定
    
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    double m = 0;
    m = max(a, b, c) * 1.0 / (max(a + b, b, c) * max(a, b, b + c));

    printf("%.3lf\n", m);

    return 0;
}
