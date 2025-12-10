//# P10495 阶乘分解
//
//## 题目描述
//
//给定整数 $N (3 \le N \le 10^6)$，试把阶乘 $N!$ 分解质因数，按照算术基本定理的形式输出分解结果中的 $p_i$ 和 $c_i$ 即可。
//
//## 输入格式
//
//一个整数 $N$。
//
//## 输出格式
//
//$N!$ 分解质因数后的结果，共若干行，每行一对 $p_i, c_i$，表示含有 $p_i^{c_i}$ 项。按照 $p_i$ 从小到大的顺序输出。
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
//2 3
//3 1
//5 1
//```

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int n;
bool st[N];
int p[N], cnt;

void get_prime()
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            p[++cnt] = i;
        }

        for(int j = 1; 1ll * i * p[j] <= n; j++)
        {
            st[i * p[j]] = true;
            if(i % p[j] == 0) break;
        }
    }
}

int main()
{
    cin >> n;

    get_prime();

    for(int i = 1; i <= cnt; i++)
    {
        int s = 0;
        for(LL j = p[i]; j <= n; j *= p[i])
        {
            s += n / j;
        }
        cout << p[i] << " " << s << endl;
    }

    return 0;
}
