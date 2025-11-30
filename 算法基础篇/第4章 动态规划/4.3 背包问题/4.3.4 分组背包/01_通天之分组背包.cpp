//# P1757 通天之分组背包
//
//## 题目背景
//
//直达通天路·小 A 历险记第二篇
//
//## 题目描述
//
//自 $01$ 背包问世之后，小 A 对此深感兴趣。一天，小 A 去远游，却发现他的背包不同于 $01$ 背包，他的物品大致可分为 $k$ 组，每组中的物品相互冲突，现在，他想知道最大的利用价值是多少。
//
//## 输入格式
//
//两个数 $m,n$，表示一共有 $n$ 件物品，背包能承受的最大重量为 $m$。
//
//接下来 $n$ 行，每行 $3$ 个数 $a_i,b_i,c_i$，表示物品的重量，利用价值，所属组数。
//
//## 输出格式
//
//一个数，最大的利用价值。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//45 3
//10 10 1
//10 5 1
//50 400 2
//```
//
//### 输出 #1
//
//```
//10
//```
//
//## 说明/提示
//
//$0 \leq m \leq 1000$，$1 \leq n \leq 1000$，$1\leq k\leq 100$，$a_i, b_i, c_i$ 在 `int` 范围内。

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, m, cnt;
vector<PII> g[N];
int f[N];

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cnt = max(c, cnt);
        g[c].push_back({a, b});
    }

    //动态规划
    for(int i = 1; i <= cnt; i++)
    {
        for(int j = m; j >= 0; j--)
        {
            //在这一组中选择物品
            for(auto& t : g[i])
            {
                int a = t.first, b = t.second;
                if(j >= a) f[j] = max(f[j], f[j - 1] + b);
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}
