//# P3807 【模板】卢卡斯定理 / Lucas 定理
//
//## 题目背景
//
//这是一道模板题。
//
//## 题目描述
//
//给定整数 $n, m, p$ 的值，求出 $C_{n + m}^n \bmod p$ 的值。
//
//输入数据保证 $p$ 为质数。
//
//注: $C$ 表示组合数。
//
//## 输入格式
//
//**本题有多组数据**。
//
//第一行一个整数 $T$，表示数据组数。
//
//对于每组数据: 
//
//一行，三个整数 $n, m, p$。
//
//## 输出格式
//
//对于每组数据，输出一行，一个整数，表示所求的值。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2
//1 2 5
//2 1 5
//```
//
//### 输出 #1
//
//```
//3
//3
//```
//
//## 说明/提示
//
//对于 $100\%$ 的数据，$1 \leq n, m, p \leq 10^5$，$1 \leq T \leq 10$。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

LL n, m, p;
LL f[N], g[N];

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void init()
{
    int n = p - 1;
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i % p;
    }

    g[n] = qpow(f[n], p - 2, p);
    for(int i = n - 1; i >= 0; i--)
    {
        g[i] = ((i + 1) * g[i + 1]) % p;
    }
}

LL C(int n, int m, int p)
{
    if(n < m) return 0;
    return f[n] * g[m] % p * g[n - m] % p;
}

LL lucas(LL n, LL m, LL p)
{
    if(m == 0)
    {
        return 1;
    }
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> p;
        init();
        cout << lucas(n + m, m, p) << endl;
    }

    return 0;
}
