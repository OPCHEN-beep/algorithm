//# P1450 [HAOI2008] 硬币购物
//
//## 题目描述
//
//共有 $4$ 种硬币。面值分别为 $c_1,c_2,c_3,c_4$。
//
//某人去商店买东西，去了 $n$ 次，对于每次购买，他带了 $d_i$ 枚 $i$ 种硬币，想购买 $s$ 的价值的东西。请问每次有多少种付款方法。
//
//## 输入格式
//
//输入的第一行是五个整数，分别代表 $c_1,c_2,c_3,c_4, n$。
//
//接下来 $n$ 行，每行有五个整数，描述一次购买，分别代表 $d_1, d_2, d_3, d_4,s$。
//
//## 输出格式
//
//对于每次购买，输出一行一个整数代表答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1 2 5 10 2
//3 2 3 1 10
//1000 2 2 2 900
//```
//
//### 输出 #1
//
//```
//4
//27
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//* 对于 $100\%$ 的数据，保证 $1 \leq c_i, d_i, s \leq 10^5$，$1 \leq n \leq 1000$。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 10, M = 1e5 + 10;

int n, s;
LL c[N], d[N];
LL f[M];

void init()
{
    f[0] = 1;
    for(int i = 0; i < 4; i++)
        for(int j = c[i]; j <= 1e5; j++)
            f[j] += f[j - c[i]];
}

int main()
{
    for(int i = 0; i < 4; i++) cin >> c[i];
    cin >> n;

    init();

    while(n--)
    {
        for(int i = 0; i < 4; i++) cin >> d[i];
        cin >> s;

        LL ret = 0;
        for(int st = 0; st < (1 << 4); st++)
        {
            LL cnt = 0, sum = 0;
            for(int i = 0; i < 4; i++)
            {
                if((st >> i) & 1)
                {
                    cnt++;
                    sum += (d[i] + 1) * c[i];
                }
            }

            if(sum > s) continue;

            if(cnt % 2 == 0) ret += f[s - sum];
            else ret -= f[s - sum];
        }

        cout << ret << endl;
    }

    return 0;
}
