//# P2136 拉近距离
//
//## 题目背景
//
//我是源点，你是终点。我们之间有负权环。 ——小明
//
//## 题目描述
//
//在小明和小红的生活中，有 $N$ 个关键的节点。有 $M$ 个事件，记为一个三元组 $(S_i,T_i,W_i)$，表示从节点 $S_i$ 有一个事件可以转移到 $T_i$，事件的效果就是使他们之间的距离减少 $W_i$。
//
//这些节点构成了一个网络，其中节点 $1$ 和 $N$ 是特殊的，节点 $1$ 代表小明，节点 $N$ 代表小红，其他代表进展的阶段。所有事件可以自由选择是否进行，但每次只能进行当前节点邻接的。请你帮他们写一个程序，计算出他们之间可能的最短距离。
//
//## 输入格式
//
//第一行，两个正整数 $N,M$。
//
//之后 $M$ 行，每行 $3$ 个空格隔开的整数 $S_i,T_i,W_i$。
//
//## 输出格式
//
//一行，一个整数表示他们之间可能的最短距离。如果这个距离可以无限缩小，输出``Forever love``。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 3
//1 2 3
//2 3 -1
//3 1 -10
//```
//
//### 输出 #1
//
//```
//-2
//```
//
//## 说明/提示
//
//对于 $20\%$ 数据，$N \le 10$，$M \le 50$。
//
//对于 $50\%$ 数据，$N \le 300$，$M \le 5000$。
//
//对于 $100\%$ 数据，$1\le N \le 10^3$，$1\le M \le 10^4$，$|W_i|\le 100$，保证从节点 $1$ 到 $2 \dots N$ 有路径，从节点 $N$ 到 $1 \dots N - 1$ 有路径。

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10, M = 1e4 + 10;

int n, m;

struct node
{
    int a, b, c;
}e[M];

int dist[N];

bool bf(int s)
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    bool flag;
    for(int i = 1; i <= n; i++)
    {
        flag = false;

        for(int j = 1; j <= m; j++)
        {
            int a = e[j].a, b = e[j].b, c = e[j].c;
            if(dist[a] + c < dist[b])
            {
                flag = true;
                dist[b] = dist[a] + c;
            }
        }

        if(flag == false) return flag;
    }

    return flag;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].a >> e[i].b >> e[i].c;
        e[i].c = -e[i].c;
    }

    int ret;
    bool st = bf(1);
    if(st)
    {
        cout << "Forever love" << endl;
        return 0;
    }

    ret = dist[n];

    st = bf(n);
    if(st)
    {
        cout << "Forever love" << endl;
        return 0;
    }

    cout << min(ret, dist[1]) << endl;

    return 0;
}
