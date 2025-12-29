//# P2455 [SDOI2006] 线性方程组
//
//## 题目描述
//
//已知 $n$ 元线性一次方程组。
//
//$$ \begin{cases} a_{1, 1} x_1 + a_{1, 2} x_2 + \cdots + a_{1, n} x_n = b_1 \\ a_{2, 1} x_1 + a_{2, 2} x_2 + \cdots + a_{2, n} x_n = b_2 \\ \cdots \\ a_{n,1} x_1 + a_{n, 2} x_2 + \cdots + a_{n, n} x_n = b_n \end{cases}$$
//
//请根据输入的数据，编程输出方程组的解的情况。
//
//## 输入格式
//
//第一行输入未知数的个数 $n$。  
//接下来 $n$ 行，每行 $n + 1$ 个整数，表示每一个方程的系数及方程右边的值。
//
//## 输出格式
//
//如果有唯一解，则输出解。你的结果被认为正确，当且仅当对于每一个 $x_i$ 而言结果值与标准答案值的绝对误差或者相对误差不超过 $0.01$。
//
//如果方程组无解输出 $-1$；
//如果有无穷多实数解，输出 $0$；
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//2 -1 1 1
//4 1 -1 5
//1 1 1 0
//```
//
//### 输出 #1
//
//```
//x1=1.00
//x2=0.00
//x3=-1.00
//```
//
//## 说明/提示
//
//【数据范围】  
//对于 $100\%$ 的数据，$1 \le n \le 50$。$\forall 1\le i, j \le n$，有 $\left | a_{i, j} \right | \le 100$，$\left |b_i \right | \le 300$。

#include <iostream>
#include <cmath>

using namespace std;

const int N = 55;
const double eps = 1e-7;

int n;
double a[N][N];

inline bool zero(double x)
{
    return fabs(x) < eps;
}

int gauss()
{
    for(int i = 1; i <= n; i++)
    {
        int aim = i;
        for(int j = 1; j <= n; j++)
        {
            if(j < i && !zero(a[j][j])) continue;
            if(fabs(a[j][i]) > fabs(a[aim][i])) aim = j;
        }

        if(zero(a[aim][i])) continue;

        for(int j = 1; j <= n + 1; j++) swap(a[aim][j], a[i][j]);
        for(int j = n + 1; j >= i; j--) a[i][j] /= a[i][i];

        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            double t = a[j][i] / a[i][i];
            for(int k = i; k <= n + 1; k++)
            {
                a[j][k] -= a[i][k] * t;
            }
        }
    }

    int ret = 1;
    for(int i = 1; i <= n; i++)
    {
        if(zero(a[i][i]) && !zero(a[i][n + 1]))
        {
            ret = 0;
            break;
        }
        if(zero(a[i][i])) ret = 2;
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n + 1; j++)
            cin >> a[i][j];

    int ret = gauss();

    if(ret == 0) cout << -1 << endl;
    else if(ret == 2) cout << 0 << endl;
    else
    {
        for(int i = 1; i <= n; i++)
            printf("x%d=%.2lf\n", i, a[i][n + 1]);
    }

    return 0;
}
