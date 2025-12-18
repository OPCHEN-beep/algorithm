//# P6191 [USACO09FEB] Bulls And Cows S
//
//## 题目背景
//
//一年一度的展会要来临了，Farmer John 想要把 $N$（$1 \leq N \leq 100,000$）只奶牛和公牛安排在单独的一行中。 John 发现最近公牛们非常好斗；假如两只公牛在这一行中靠的太近，他们就会吵架，以至于斗殴，破坏这和谐的环境。
//
//## 题目描述
//
//John 非常的足智多谋，他计算出任何两只公牛之间至少要有 $K$（$0 \leq K \lt N$）只奶牛，这样才能避免斗殴。John 希望你帮助他计算一下有多少种安排方法，可避免任何斗殴的的发生。John 认为每头公牛都是一样的，每头奶牛都是一样的。因而，只要在一些相同的位置上有不同种类的牛，那这就算两种不同的方法。
//
//## 输入格式
//
//两个整数 $N$ 和 $K$。
//
//## 输出格式
//
//输出约翰可以安排的方法数。考虑到这个数可能很大，你只要输出对 $5\,000\,011$ 取模之后的结果就可以了。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4 2
//```
//
//### 输出 #1
//
//```
//6
//```
//
//## 说明/提示
//
//下面的就是 FJ 思考出可行的 6 种方案（C 代表奶牛，B 代表公牛）：
//- CCCC
//- BCCC
//- CBCC
//- CCBC
//- CCCB
//- BCCB

#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10, MOD = 5000011;

int n, k;
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
    for(int i = 1; i <= n; i++) f[i] = i * f[i - 1] % MOD;

    g[n] = qpow(f[n], MOD - 2, MOD);
    for(int i = n - 1; i >= 0; i--) g[i] = (i + 1) * g[i + 1] % MOD;
}

LL C(int n, int m)
{
    if(n < m) return 0;

    return f[n] * g[n - m] % MOD * g[m] % MOD;
}

int main()
{
    cin >> n >> k;

    init();

    LL ret = 1;
    for(int i = 1; i <= n; i++)
    {
        ret = (ret + C(n - (i - 1) * k, i)) % MOD;
    }

    cout << ret << endl;

    return 0;
}
