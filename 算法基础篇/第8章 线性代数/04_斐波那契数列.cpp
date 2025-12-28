//# P1962 斐波那契数列
//
//## 题目描述
//
//大家都知道，斐波那契数列是满足如下性质的一个数列：
//
//$$F_n = \left\{\begin{aligned} 1 \space (n \le 2) \\ F_{n-1}+F_{n-2} \space (n\ge 3) \end{aligned}\right.$$
//
//
//请你求出 $F_n \bmod 10^9 + 7$ 的值。
//
//## 输入格式
//
//一行一个正整数 $n$。
//
//## 输出格式
//
//输出一行一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//```
//
//### 输出 #1
//
//```
//5
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//10
//```
//
//### 输出 #2
//
//```
//55
//```
//
//## 说明/提示
//
//【数据范围】    
//对于 $60\%$ 的数据，$1\le n \le 92$；   
//对于 $100\%$ 的数据，$1\le n < 2^{63}$。

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 3, MOD = 1e9 + 7;

LL n;

struct mat
{
    LL m[N][N];

    mat()
    {
        memset(m, 0, sizeof m);
    }

    mat operator*(const mat& B) const
    {
        mat C;
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= 2; j++)
                for(int k = 1; k <= 2; k++)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j]) % MOD;
        return C;
    }
}A, RET;

void qpow(LL b)
{
    RET.m[1][1] = RET.m[1][2] = 1;
    A.m[1][1] = A.m[1][2] = A.m[2][1] = 1;

    while(b)
    {
        if(b & 1) RET = RET * A;
        b >>= 1;
        A = A * A;
    }
}

int main()
{
    cin >> n;

    if(n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    qpow(n - 2);

    cout << RET.m[1][1] << endl;

    return 0;
}
