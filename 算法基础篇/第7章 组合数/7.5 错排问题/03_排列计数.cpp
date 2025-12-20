//# P4071 [SDOI2016] 排列计数
//
//## 题目描述
//
//求有多少种 $1$ 到 $n$ 的排列 $a$，满足序列恰好有 $m$ 个位置 $i$，使得 $a_i = i$。
//
//答案对 $10^9 + 7$ 取模。
//
//## 输入格式
//
//**本题单测试点内有多组数据**。
//
//输入的第一行是一个整数 $T$，代表测试数据的组数。
//
//以下 $T$ 行，每行描述一组测试数据。
//
//对于每组测试数据，每行输入两个整数，依次代表 $n$ 和 $m$。
//
//## 输出格式
//
//共输出 $T$ 行，对于每组测试数据，输出一行一个整数代表答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//1 0
//1 1
//5 2
//100 50
//10000 5000
//```
//
//### 输出 #1
//
//```
//0
//1
//20
//578028887
//60695423
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//本题共 20 个测试点，各测试点等分，其数据规模如下表。
//
//| 测试点编号 | $T =$  | $n, m \leq$ |  测试点编号  |      $T =$      | $n, m \leq$ |
//| :--------: | :----: | :---------: | :----------: | :-------------: | :---------: |
//| $1\sim 3$  | $10^3$ |     $8$     | $10 \sim 12$ |     $10^3$      |   $10^3$    |
//| $4 \sim 6$ | $10^3$ |    $12$     | $13 \sim 14$ | $5 \times 10^5$ |   $10^3$    |
//| $7 \sim 9$ | $10^3$ |    $100$    | $15 \sim 20$ | $5 \times 10^5$ |   $10^6$    |
//
//对于全部的测试点，保证 $1 \leq T \leq 5 \times 10^5$，$1 \leq n \leq 10^6$，$0 \leq m \leq 10^6$。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10, MOD = 1e9 + 7;

int n, m;
LL f[N], g[N], d[N];

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
    int n = 1e6;

    f[0] = 1;
    for(int i = 1; i<= n; i++) f[i] = i * f[i - 1] % MOD;

    g[n] = qpow(f[n], MOD - 2, MOD);
    fo(int i = n - 1; i >= 0; i--) g[i] = (i + 1) * g[i + 1] % MOD;

    d[2] = 1;
    for(int i = 3; i<= n; i++) d[i] = ((i - 1) * ((d[i - 1]) % MOD)) % MOD;
}

LL C(int n. int m)
{
    if(n < m) return 0;
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}

int main()
{
    init();

    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        if(n < m) cout << 0 << endl;
        else if( n == m) cout << 1 << endl;
        else cout << C(n, m) * d[n - m] % MOD << endl;
    }

    return 0;
}
