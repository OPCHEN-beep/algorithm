//# P1835 素数密度
//
//## 题目背景
//
//UPD:
//
//- 2024.8.12：加入一组 Hack 数据。
//
//## 题目描述
//
//给定 $L,R$，请计算区间 $[L,R]$ 中素数的个数。
//
//   $1\leq L\leq R < 2^{31}$，$R-L\leq 10^6$。
//
//## 输入格式
//
//第一行，两个正整数 $L$ 和 $R$。
//
//## 输出格式
//
//一行，一个整数，表示区间中素数的个数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 11
//```
//
//### 输出 #1
//
//```
//5
//```

#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;

int l, r;
bool st[N];
int p[N], cnt;

bool ret[N];

void get_prime()
{
    int n = sqrt(r);
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) p[++cnt] = i;

        for(int j = 1; 1ll * i * p[j] <= n; j++)
        {
            st[i * p[j]] = true;
            if(i % p[j] == 0) break;
        }
    }
}

int main()
{
    cin >> l >> r;
    
    get_prime();

    l = l == 1 ? 2 : l;
    for(int i = 1; i <= cnt; i++)
    {
        LL x = p[i];
        for(LL j = max(x * 2, (x + l - 1) / x * x); j <= r; j += x)
        {
            ret[j - l] = true;
        }
    }

    int sum = 0;
    for(int i = l; i <= r; i++)
    {
        if(!ret[i - l]) sum++;
    }

    cout << sum << endl;
    
    return 0;
}
