//# P4783 【模板】矩阵求逆
//
//## 题目描述
//
//求一个 $N\times N$ 的矩阵的逆矩阵。答案对 ${10}^9+7$ 取模。
//
//## 输入格式
//
//第一行有一个整数 $N$，代表矩阵的大小；
//
//接下来 $N$ 行，每行 $N$ 个整数，其中第 $i$ 行第 $j$ 列的数代表矩阵中的元素 $a_{i j}$。
//
//## 输出格式
//
//若矩阵可逆，则输出 $N$ 行，每行 $N$ 个整数，其中第 $i$ 行第 $j$ 列的数代表逆矩阵中的元素 $b_{i j}$，答案对 ${10}^9+7$ 取模；
//
//否则只输出一行 `No Solution`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//1 2 8
//2 5 6
//5 1 2
//```
//
//### 输出 #1
//
//```
//718750005 718750005 968750007
//171875001 671875005 296875002
//117187501 867187506 429687503
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//3
//3 2 4
//7 2 9
//2 4 3
//```
//
//### 输出 #2
//
//```
//No Solution
//```
//
//## 说明/提示
//
//对 $30 \%$ 的数据有 $N\le 100$；  
//对 $100 \%$ 的数据有 $N\le 400$，所有 $0 \le a_{i j} < {10}^9 + 7$。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 410, MOD = 1e9 + 7;

int n;
LL a[N][N + N];

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

int gauss()
{
    for(int i = 1; i <= n; i++)
    {
        int aim = i;
        for(int j = 1; j <= n; j++)
        {
            if(j < i && a[j][i] != 0) continue;
            if(a[j][i] > a[aim][i]) aim = j;
        }

        if(a[aim][i] == 0) return 0;

        for(int j = 1; j <= n + n; j++) swap(a[i][j], a[aim][j]);

        LL t = qpow(a[i][i], MOD - 2, MOD);

        for(int j = i; j <= n + n; j++) a[i][j] = a[i][j] * t % MOD;

        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            t = a[j][i];
            for(int k = i; k <= n + n; k++)
            {
                a[j][k] -= a[i][k] * t;
                a[j][k] = (a[j][k] % MOD + MOD) % MOD;
            }
        }
    }
    return 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++) a[i][i + n] = 1;

    int ret = gauss();

    if(ret == 0) cout << "No Solution" << endl;
    else
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = n + 1; j <= n + n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
