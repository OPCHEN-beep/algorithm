//# P3182 [HAOI2016] 放棋子
//
//## 题目描述
//
//给你一个 $N\times N$ 的矩阵，每行有一个障碍，数据保证任意两个障碍不在同一行，任意两个障碍不在同一列，要求你在这个矩阵上放 $N$ 枚棋子（障碍的位置不能放棋子），要求你放 $N$ 个棋子也满足每行只有一枚棋子，每列只有一枚棋子的限制，求有多少种方案。
//
//## 输入格式
//
//第一行一个 $N$，接下来一个 $N \times N$ 的矩阵。$N\leq 200$，0 表示没有障碍，1 表示有障碍。
//
//## 输出格式
//
//一个整数，即合法的方案数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2
//0 1
//1 0
//```
//
//### 输出 #1
//
//```
//1
//```

#include <iostream>

using namespace std;

const int N = 210, M = 500;

int n;
int f[N][M];

void add(int a[], int b[], int c[])
{
    for(int i = 0; i < M - 1; i++)
    {
        a[i] += b[i] + c[i];
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
}

void mul(int a[], int x)
{
    int t = 0;
    for(int i = 0; i < M - 1; i++)
    {
        t = t + a[i] * x;
        a[i] = t % 10;
        t /= 10;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> f[0][0];

    f[2][0] = 1;
    for(int i = 3; i <= n; i++)
    {
        add(f[i], f[i - 1], f[i - 2]);
        mul(f[i], i - 1);
    }

    int p = M - 1;
    while(f[n][p] == 0) p--;
    while(p >= 0) cout << f[n][p--];

    return 0;
}
