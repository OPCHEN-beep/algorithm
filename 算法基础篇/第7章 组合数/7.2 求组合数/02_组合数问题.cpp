//# B3717 组合数问题
//
//## 题目背景
//
//**禁止套取数据提交。违者将处罚。**
//
//## 题目描述
//
//给出 $T$ 次询问，每次给出 $n,m$，请求出 $\binom{n}{m}$ 对 $998,244,353$ 取模的结果。
//
//其中 $\binom{n}{m}$ 为二项式系数，它的另一种写法是 $C_n^m$。
//
//## 输入格式
//
//输入的第一行是两个整数，分别表示询问的次数 $T$ 和所给出 $n$ 的最大值 $N$。  
//接下来 $T$ 行，每行两个整数，依次表示给出的 $n$ 和 $m$。
//
//## 输出格式
//
//为了避免输出过大，请你输出一行一个整数，表示所有询问的结果的**按位异或和**。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 5
//3 3
//4 2
//5 3
//```
//
//### 输出 #1
//
//```
//13
//```
//
//## 说明/提示
//
//### 样例 1 解释
//
//三组询问的答案依次是 $1, 6, 10$。
//
//### 数据规模与约定
//
//对 $100\%$ 的数据，保证 $1 \leq T \leq 5 \times 10^6$，$0 \leq m \leq n \leq N \leq 5 \times 10^6$。
//
//### 提示
//
//请注意大量的数据读入对程序效率造成的影响，选择合适的读入方式，避免超时。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 5e6 + 10, MOD = 998244353;

int n;
LL f[N], g[N];

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

void init()
{
    f[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i % MOD;
    }

    g[n] = qpow(f[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--)
    {
        g[i] = (i + 1) * g[i + 1] % MOD;
    }
}

int main()
{
    int T;
    scanf("%d%d", &T, &n);

    init();

    LL ret = 0;
    while(T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        ret ^= (f[n] * g[n - m] % MOD * g[m] % MOD);
    }

    printf("%lld\n", ret);

    return 0;
}
