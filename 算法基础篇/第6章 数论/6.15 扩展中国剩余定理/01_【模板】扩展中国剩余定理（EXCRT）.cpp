//# P4777 【模板】扩展中国剩余定理（EXCRT）
//
//## 题目描述
//
//给定 $n$ 组非负整数 $a_i, b_i$ ，求解关于 $x$ 的方程组的最小非负整数解。
//$$\begin{cases}x\equiv b_1\pmod{a_1}\\x\equiv b_2\pmod{a_2}\\\dots\\x\equiv b_n\pmod{a_n}\end{cases}$$
//
//## 输入格式
//
//输入第一行包含整数 $n$。
//
//接下来 $n$ 行，每行两个非负整数 $a_i, b_i$。
//
//## 输出格式
//
//输出一行，为满足条件的最小非负整数 $x$。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//11 6
//25 9
//33 17
//```
//
//### 输出 #1
//
//```
//809
//```
//
//## 说明/提示
//
//对于 $100 \%$ 的数据，$1 \le n \le {10}^5$，$1 \le a_i \le {10}^{12}$，$0\leq b_i \leq 10^{12}$，保证所有 $a_i$ 的最小公倍数不超过 ${10}^{18}$。
//
//**请注意程序运行过程中进行乘法运算时结果可能有溢出的风险。**
//
//数据保证有解。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
LL m[N], r[N];

LL qmul(LL a, LL b, LL p)
{
    LL sum = 0;
    while(b)
    {
        if(b & 1) sum = (sum + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return sum;
}

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL x1, y1;
    LL d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}

LL excrt()
{
    LL M = 1, ret = 0;
    for(int i = 1; i <= n; i++)
    {
        LL a = M, b = m[i], c = r[i] - ret;

        c = (c % b + b) % b;

        LL x, y, d;
        d = exgcd(a, b, x, y);
        if(c % d) return -1;

        LL k1 = b / d;
        x = qmul(x, c / d, k1);
        x = (x % k1 + k1) % k1;

        ret = ret + x * M;
        M = k1 * M;
        ret = (ret % M + M) % M;
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> m[i] >> r[i];

    cout << excrt() << endl;

    return 0;
}
