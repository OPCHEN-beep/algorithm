//# B3647 【模板】Floyd
//
//## 题目描述
//
//给出一张由 $n$ 个点 $m$ 条边组成的无向图。
//
//求出所有点对 $(i,j)$ 之间的最短路径。
//
//## 输入格式
//
//第一行为两个整数 $n,m$，分别代表点的个数和边的条数。
//
//接下来 $m$ 行，每行三个整数 $u,v,w$，代表 $u,v$ 之间存在一条边权为 $w$ 的边。
//
//## 输出格式
//
//输出 $n$ 行每行 $n$ 个整数。
//
//第 $i$ 行的第 $j$ 个整数代表从 $i$ 到 $j$ 的最短路径。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4 4
//1 2 1
//2 3 1
//3 4 1
//4 1 1
//```
//
//### 输出 #1
//
//```
//0 1 2 1
//1 0 1 2
//2 1 0 1
//1 2 1 0
//```
//
//## 说明/提示
//
//对于 $100\%$ 的数据，$n \le 100$，$m \le 4500$，任意一条边的权值 $w$ 是正整数且 $1 \leqslant w \leqslant 1000$。
//
//**数据中可能存在重边。**

#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int f[N][N];

int main()
{
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= n; i++) f[i][i] = 0;
    for(int i = 1; i <= m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << f[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
