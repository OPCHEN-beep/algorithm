//# P1939 矩阵加速（数列）
//
//## 题目描述
//
//已知一个数列 $a$，它满足：  
//
//$$
//a_x=
//\begin{cases}
// 1 & x \in\{1,2,3\}\\ 
// a_{x-1}+a_{x-3} & x \geq 4
//\end{cases}
//$$
//
//求 $a$ 数列的第 $n$ 项对 $10^9+7$ 取余的值。
//
//## 输入格式
//
//第一行一个整数 $T$，表示询问个数。
//
//以下 $T$ 行，每行一个正整数 $n$。
//
//## 输出格式
//
//每行输出一个非负整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//6
//8
//10
//```
//
//### 输出 #1
//
//```
//4
//9
//19
//```
//
//## 说明/提示
//
//- 对于 $30\%$ 的数据 $n \leq 100$；
//- 对于 $60\%$ 的数据 $n \leq2 \times 10^7$；
//- 对于 $100\%$ 的数据 $1 \leq T \leq 100$，$1 \leq n \leq 2 \times 10^9$。

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5, MOD = 1e9 + 7;

int n;

struct mat
{
    LL m[N][N];

    mat()
    {
        memset(m, 0, sizeof m);
    }

    void clear()
    {
        memset(m, 0, sizeof m);
    }

    mat operator*(const mat& B) const
    {
        mat C;
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++)
                for(int k = 1; k <= 3; k++)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j]) % MOD;
        return C;
    }
}A, RET;

void qpow(LL b)
{
    RET.m[1][1] = RET.m[1][2] = RET.m[1][3] = 1;
    A.m[1][1] = A.m[1][2] = A.m[2][3] = A.m[3][1] = 1;

    while(b)
    {
        if(b & 1) RET = RET * A;
        b >>= 1;
        A = A * A;
    }
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        cin >> n;

        if(n == 1 || n == 2 || n == 3)
        {
            cout << 1 << endl;
            continue;
        }

        A.clear();
        RET.clear();

        qpow(n - 3);

        cout << RET.m[1][1] << endl;
    }
    
    return 0;
}
