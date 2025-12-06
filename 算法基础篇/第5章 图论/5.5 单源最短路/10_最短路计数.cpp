//# P1144 最短路计数
//
//## 题目描述
//
//给出一个 $N$ 个顶点 $M$ 条边的无向无权图，顶点编号为 $1\sim N$。问从顶点 $1$ 开始，到其他每个点的最短路有几条。
//
//## 输入格式
//
//第一行包含 $2$ 个正整数 $N,M$，为图的顶点数与边数。
//
//接下来 $M$ 行，每行 $2$ 个正整数 $x,y$，表示有一条连接顶点 $x$ 和顶点 $y$ 的边，请注意可能有自环与重边。
//
//## 输出格式
//
//共 $N$ 行，每行一个非负整数，第 $i$ 行输出从顶点 $1$ 到顶点 $i$ 有多少条不同的最短路，由于答案有可能会很大，你只需要输出 $ ans \bmod 100003$ 后的结果即可。如果无法到达顶点 $i$ 则输出 $0$。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5 7
//1 2
//1 3
//2 4
//3 4
//2 3
//4 5
//4 5
//```
//
//### 输出 #1
//
//```
//1
//1
//1
//2
//4
//```
//
//## 说明/提示
//
//$1$ 到 $5$ 的最短路有 $4$ 条，分别为 $2$ 条 $1\to 2\to 4\to 5$ 和 $2$ 条 $1\to 3\to 4\to 5$（由于 $4\to 5$ 的边有 $2$ 条）。
//
//对于 $20\%$ 的数据，$1\le N \le 100$；  
//对于 $60\%$ 的数据，$1\le N \le 10^3$；  
//对于 $100\%$ 的数据，$1\le N\le10^6$，$1\le M\le 2\times 10^6$。

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10, M = 2e6 + 10, MOD = 100003;

int n, m;
vector<int> edges[N];

int dist[N];
bool st[N];
int f[N];

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);

    dist[1] = 0;
    f[1] = 1;

    while(q.size())
    {
        auto a = q.front(); q.pop();

        for(auto b : edges[a])
        {
            if(dist[a] + 1 < dist[b])
            {
                dist[b] = dist[a] + 1;
                f[b] = f[a];
                q.push(b);
            }
            else if(dist[a] + 1 == dist[b])
            {
                f[b] = (f[b] + f[a]) % MOD;
            }
        }
    }
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    dist[1] = 0;
    f[1] = 1;

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int a = t.second;

        if(st[a]) continue;
        st[a] = true;

        for(auto b : edges[a])
        {
            if(dist[a] + 1 < dist[b])
            {
                dist[b] = dist[a] + 1;
                f[b] = f[a];
                heap.push({dist[b], b});
            }
            else if(dist[a] + 1 == dist[b])
            {
                f[b] = (f[a] + f[b]) % MOD;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dijkstra();

    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", f[i]);
    }

    return 0;
}
