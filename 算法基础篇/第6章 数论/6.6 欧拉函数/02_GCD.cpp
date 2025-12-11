//# P2568 GCD
//
//## 题目描述
//
//给定正整数 $n$，求 $1\le x,y\le n$ 且 $\gcd(x,y)$ 为素数的数对 $(x,y)$ 有多少对。
//
//## 输入格式
//
//只有一行一个整数，代表 $n$。
//
//## 输出格式
//
//一行一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4
//```
//
//### 输出 #1
//
//```
//4
//```
//
//## 说明/提示
//
//#### 样例输入输出 1 解释
//
//对于样例，满足条件的 $(x,y)$ 为 $(2,2)$，$(2,4)$，$(3,3)$，$(4,2)$。
//
//---
//
//#### 数据规模与约定
//
//- 对于 $100\%$ 的数据，保证 $1\le n\le10^7$。
//
//---
//
//来源：bzoj2818。
//
//本题数据为洛谷自造数据，使用 [CYaRon](https://github.com/luogu-dev/cyaron) 耗时 $5$ 分钟完成数据制作。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

int n;
bool st[N];
int p[N], cnt;
int phi[N];
LL f[N];

void get_phi()
{
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            phi[i] = i - 1;
            p[++cnt] = i;
        }

        for(int j = 1; 1ll * i *p[j] <= n; j++)
        {
            int x = i * p[j];
            st[x] = true;

            if(i % p[j] == 0)
            {
                phi[x] = phi[i] * p[j];
                break;
            }
            else
            {
                phi[x] = phi[i] * (p[j] - 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    get_phi();

    for(int i = 1; i <= n; i++) f[i] = f[i - 1] + phi[i];

    LL sum = 0;
    for(int i = 1; i <= cnt; i++)
    {
        sum += f[n / p[i]] * 2 - 1;
    }
    cout << sum << endl;

    return 0;
}
