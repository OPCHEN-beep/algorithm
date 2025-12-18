//# P1350 车的放置
//
//## 题目描述
//
//有下面这样的一个网格棋盘，$a,b,c,d$ 表示了对应边长度，也就是对应格子数：
//
//![](https://cdn.luogu.com.cn/upload/image_hosting/g7ulpevu.png)
//
//当 $a=b=c=d=2$ 时，对应下面这样一个棋盘：
//
//![](https://cdn.luogu.com.cn/upload/image_hosting/e2ntmjlk.png)
//
//要在这个棋盘上放 $k$ 个相互不攻击的车，也就是这 $k$ 个车没有两个车在同一行，也没有两个车在同一列，问有多少种方案。
//
//## 输入格式
//
//只有一行，为五个非负整数，分别代表 $a,b,c,d$ 和 $k$。
//
//## 输出格式
//
//输出一行一个整数代表答案 $\bmod$ $10^5+3$ 后的结果。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 2 2 2 2
//```
//
//### 输出 #1
//
//```
//38
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//- 存在部分数据，保证 $b=0$；
//- 存在部分数据，保证 $a,b,c,d\leq 4$。
//- 对于 $100\%$ 的数据，保证 $0\leq a,b,c,d,k\leq 10^3$，且至少有一种可行方案。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e3 + 10, MOD = 1e5 + 3;

LL a, b, c, d, k;
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
    int n = 2000;
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = i * f[i - 1] % MOD;

    g[n] = qpow(f[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--) g[i] = (i + 1) * g[i + 1] % MOD;
}

LL C(int n, int m)
{
    if(n < m)  return 0;
    return f[n] * g[n - m] % MOD * g[m] % MOD;
}

int main()
{
    init();

    cin >> a >> b >> c >> d >> k;

    LL ret = 0;
    for(int x = 0; x <= k; x++)
    {
        LL l = C(d,x) * C(c, x) % MOD * f[x] % MOD;
        LL r = C(b + d - x, k - x) * C(a, k - x) % MOD * f[k - x] % MOD;
        ret = (ret + l * r % MOD) % MOD;
    }

    cout << ret << endl;

    return 0;
}
