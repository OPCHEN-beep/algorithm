//# P3390 【模板】矩阵快速幂
//
//## 题目背景
//
//一个 $m \times n$ 的**矩阵**是一个由 $m$ 行 $n$ 列元素排列成的矩形阵列。即形如
//
//$$ A = \begin{bmatrix} a_{1 1} & a_{1 2} & \cdots & a_{1 n} \\ a_{2 1} & a_{2 2} & \cdots & a_{2 n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m 1} & a_{m 2} & \cdots & a_{m n} \end{bmatrix} \text{.} $$
//
//本题中认为矩阵中的元素 $a_{i j}$ 是整数。
//
//两个大小分别为 $m \times n$ 和 $n \times p$ 的矩阵 $A, B$ **相乘**的结果为一个大小为 $m \times p$ 的矩阵。将结果矩阵记作 $C$，则
//
//$$ c_{i j} = \sum_{k = 1}^{n} a_{i k} b_{k j} \text{,\qquad($1 \le i \le m$, $1 \le j \le p$).} $$
//
//而如果 $A$ 的列数与 $B$ 的行数不相等，则无法进行乘法。
//
//可以验证，矩阵乘法满足结合律，即 $(A B) C = A (B C)$。
//
//一个大小为 $n \times n$ 的矩阵 $A$ 可以与自身进行乘法，得到的仍是大小为 $n \times n$ 的矩阵，记作 $A^2 = A \times A$。进一步地，还可以递归地定义任意高次方 $A^k = A \times A^{k - 1}$，或称 $A^k = \underbrace{A \times A \times \cdots \times A}_{k \text{ 次}}$。
//
//特殊地，定义 $A^0$ 为单位矩阵 $I = \begin{bmatrix} 1 & 0 & \cdots & 0 \\ 0 & 1 & \cdots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & \cdots & 1 \end{bmatrix}$。
//
//## 题目描述
//
//给定 $n\times n$ 的矩阵 $A$，求 $A^k$。
//
//## 输入格式
//
//第一行两个整数 $n,k$。  
//接下来 $n$ 行，每行 $n$ 个整数，第 $i$ 行的第 $j$ 的数表示 $A_{i,j}$。
//
//## 输出格式
//
//输出 $A^k$
//
//共 $n$ 行，每行 $n$ 个数，第 $i$ 行第 $j$ 个数表示 $(A^k)_{i,j}$，每个元素对 $10^9+7$ 取模。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 1
//1 1
//1 1
//```
//
//### 输出 #1
//
//```
//1 1
//1 1
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//3 5
//1 2 3
//4 5 6
//7 8 9
//```
//
//### 输出 #2
//
//```
//121824 149688 177552
//275886 338985 402084
//429948 528282 626616
//```
//
//## 说明/提示
//
//**【数据范围】**
//
//对于 $100\%$ 的数据，$1\le n \le 100$，$0 \le k \le 10^{12}$，$|A_{i,j}| \le 1000$。

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 110, MOD = 1e9 + 7;

LL n, k;

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
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++)
                    C.m[i][j] = (C.m[i][j] + (m[i][k] * B.m[k][j])) % MOD;
        return C;
    }
}A, RET;

void qpow(LL b)
{
    for(int i = 1; i <= n; i++) RET.m[i][i] = 1;

    while(b)
    {
        if(b & 1) RET = RET * A;
        b >>= 1;
        A = A * A;
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A.m[i][j];

    qpow(k);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << RET.m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
