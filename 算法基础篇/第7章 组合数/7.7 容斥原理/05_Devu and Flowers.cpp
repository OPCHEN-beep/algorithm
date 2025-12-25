//# CF451E Devu and Flowers
//
//## 题目描述
//
//Devu 想用花来装饰他的花园。他买了 $n$ 个盒子，第 $i$ 个盒子里有 $f_i$ 朵花。每个盒子里的花都是同一种颜色，因此在同一个盒子里的花没有区别。而且不同盒子里的花颜色也不相同。
//
//现在，Devu 想要从这些盒子中恰好选出 $s$ 朵花来装饰他的花园。他想知道，有多少种不同的选取方式可以从每个盒子中选花。由于这个数可能非常大，请你输出答案对 $(10^9+7)$ 取模的结果。
//
//如果存在至少一个盒子，在两种选法中选择的花的数量不同，Devu 就认为这两种方式是不同的。
//
//## 输入格式
//
//输入的第一行包含两个用空格分隔的整数 $n$ 和 $s$（$1 \leq n \leq 20$，$0 \leq s \leq 10^{14}$）。
//
//第二行包含 $n$ 个用空格分隔的整数 $f_1, f_2, \dots, f_n$（$0 \leq f_i \leq 10^{12}$）。
//
//## 输出格式
//
//输出一个整数，表示 Devu 可以选择 $s$ 朵花的不同方法数，结果对 $(10^9+7)$ 取模。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 3
//1 3
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//2 4
//2 2
//```
//
//### 输出 #2
//
//```
//1
//```
//
//## 输入输出样例 #3
//
//### 输入 #3
//
//```
//3 5
//1 3 2
//```
//
//### 输出 #3
//
//```
//3
//```
//
//## 说明/提示
//
//样例 1：有两种选 $3$ 朵花的方法：$\{1,2\}$ 和 $\{0,3\}$。
//
//样例 2：选 $4$ 朵花的方法只有一种：$\{2,2\}$。
//
//样例 3：选 $5$ 朵花的方法有三种：$\{1,2,2\}$，$\{0,3,2\}$ 和 $\{1,3,1\}$。
//
//由 ChatGPT 5 翻译

#include <iostream>

using namespace std;

typedef long long LL;
const int N = 30, MOD = 1e9 + 7;

LL n, s;
LL f[N];
LL inv;

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

LL C(LL n, LL m)
{
    if(n < m || n < 0) return 0;

    LL up = 1;
    for(LL i = n - m + 1; i <= n; i++) up = up * (i % MOD) % MOD;

    return up * inv % MOD;
}

int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> f[i];

    LL down = 1;
    for(int i = 1; i <= n; i++) down = down * i % MOD;
    inv = qpow(down, MOD - 2, MOD);

    LL ret = 0;
    for(int st = 0; st < (1 << n); st++)
    {
        LL cnt = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if((st >> i) & 1)
            {
                cnt++;
                sum += f[i] + 1;
            }
        }

        if(cnt % 2 == 0) ret += C(n + s - 1 - sum, n - 1);
        else ret -= C(n + s - 1 - sum, n - 1);
        ret = (ret % MOD + MOD) % MOD;
    }
    cout << ret << endl;

    return 0;
}
