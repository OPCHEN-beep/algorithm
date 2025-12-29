//# P4035 [JSOI2008] 球形空间产生器
//
//## 题目描述
//
//有一个球形空间产生器能够在 $n$ 维空间中产生一个坚硬的球体。现在，你被困在了这个 $n$ 维球体中，你只知道球面上 $n+1$ 个点的坐标，你需要以最快的速度确定这个 $n$ 维球体的球心坐标，以便于摧毁这个球形空间产生器。
//
//## 输入格式
//
//第一行是一个整数 $n$ $(1\le N\le 10)$。接下来的 $n+1$ 行，每行有 $n$ 个实数，表示球面上一点的 $n$ 维坐标。每一个实数精确到小数点后 $6$ 位，且其绝对值都不超过 $20000$。
//
//## 输出格式
//
//有且只有一行，依次给出球心的 $n$ 维坐标（ $n$ 个实数），两个实数之间用一个空格隔开。每个实数精确到小数点后 $3$ 位。数据保证有解。你的答案必须和标准输出一模一样才能够得分。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2
//0.0 0.0
//-1.0 1.0
//1.0 0.0
//```
//
//### 输出 #1
//
//```
//0.500 1.500
//```
//
//## 说明/提示
//
//提示：给出两个定义：
//
//1. 球心：到球面上任意一点距离都相等的点。
//2. 距离：设两个 $n$ 维空间上的点 $A,B$ 的坐标为 $(a_1, a_2, \cdots , a_n), (b_1, b_2, \cdots , b_n)$，则 $A,B$ 的距离定义为：$dist = \sqrt{ (a_1-b_1)^2 + (a_2-b_2)^2 + \cdots + (a_n-b_n)^2 }$。

#include <iostream>
#include <cmath>

using namespace std;

const int N = 15;
const double eps = 1e-7;

int n;
double a[N][N];
double b[N];

inline bool zero(double x)
{
    return fabs(x) < eps;
}

void gauss()
{
    for(int i = 1; i <= n; i++)
    {
        int aim = i;
        for(int j = 1; j <= n; j++)
        {
            if(j < i && !zero(a[j][j])) continue;
            if(abs(a[j][i]) > fabs(a[aim][i])) aim = j;
        }

        for(int j = 1; j <= n + 1; j++) swap(a[i][j], a[aim][j]);
        for(int j = n + 1; j >= i; j--) a[i][j] /= a[i][i];

        for(int j = 1; j <= n; j++)
        {
            if(j == i) continue;
            double t = a[j][i] / a[i][i];
            for(int k = i; k <= n + 1; k++)
            {
                a[j][k] -= a[i][k] * t;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++)
        {
            double x;
            cin >> x;
            a[i][j] = 2 * (x - b[j]);
            a[i][n + 1] += x * x - b[j] * b[j];
        }
    }

    gauss();

    for(int i = 1; i <= n; i++)
        printf("%.3lf ", a[i][n + 1]);

    return 0;
}
