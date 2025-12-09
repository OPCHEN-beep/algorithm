//# UVA543 Goldbach's Conjecture
//
//## 题目描述
//
//哥德巴赫猜想的内容如下：
//
//任意一个大于 $4$ 的偶数都可以拆成两个奇质数之和。
//
//比如：
//
//$
//\begin{aligned}
//8&=3+5\\
//20&=3+17=7+13\\
//42&=5+37=11+31=13+29=19+23
//\end{aligned}
//$
//
//你的任务是：验证小于 $10^6$ 的数满足哥德巴赫猜想。
//
//## 输入格式
//
//输入包含多组数据。
//
//每组数据占一行，包含一个偶数 $n(n \le 10^6)$。 读入以 $0$ 结束。
//
//## 输出格式
//
//对于每组数据，输出形如 `n = a + b`，其中 $a,b$ 是奇质数。若有多组满足条件的 $a,b$，输出 $b?a$ 最大的一组。
//
//若无解，输出 `Goldbach's conjecture is wrong.`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//8
//20
//42
//0
//```
//
//### 输出 #1
//
//```
//8 = 3 + 5
//20 = 3 + 17
//42 = 5 + 37
//```

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

bool st[N];
int p[N], cnt;

void get_prime()
{
    int n = 1e6;
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

void solve(int x)
{
    for(int i = 2; i <= cnt; i++)
    {
        if(!st[x - p[i]])
        {
            printf("%d = %d + %d\n", x, p[i], x - p[i]);
            break;
        }
    }
}

int main()
{
    get_prime();

    int x;
    while(cin >> x, x)
    {
        solve(x);
    }

    return 0;
}
