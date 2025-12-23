//# P1375 小猫
//
//## 题目描述
//
//有 $2n$ 只小猫站成一圈，主人小明想把它们两两之间用绳子绑住尾巴连在一起。同时小明是个完美主义者，不容许看到有两根绳子交叉。请问小明有几种连线方案，可以把让所有小猫两两配对？
//
//方案数很大，仅需输出方案数模 $10^9+7$（一个质数）的值。
//
//## 输入格式
//
//输入共一行，一个整数 $n$。
//
//## 输出格式
//
//输出方案数对 $10^9+7$ 取模后的值。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//```
//
//### 输出 #1
//
//```
//5
//```
//
//## 说明/提示
//
//### 数据范围
//
//- 对于 $60\%$ 的数据，$1\le N \le 100$。
//- 对于 $100\%$ 的数据，$1\le N \le 10^5$。

#include <iostream>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int n;

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

int main()
{
    cin >> n;

    LL up = 1, down = 1;

    for(int i = 2; i <= n + n; i++) up = up * i % MOD;
    for(int i = 2; i <= n; i++) down = down * i % MOD * i % MOD;
    down = down * (n + 1) % MOD;

    cout << up * qpow(down, MOD - 2, MOD) % MOD << endl;

    return 0;
}
