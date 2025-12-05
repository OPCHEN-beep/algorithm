//# P3385 【模板】负环
//
//## 题目描述
//
//给定一个 $n$ 个点的有向图，请求出图中是否存在**从顶点 $1$ 出发能到达**的负环。
//
//负环的定义是：一条边权之和为负数的回路。
//
//## 输入格式
//
//**本题单测试点有多组测试数据**。
//
//输入的第一行是一个整数 $T$，表示测试数据的组数。对于每组数据的格式如下：
//
//第一行有两个整数，分别表示图的点数 $n$ 和接下来给出边信息的条数 $m$。
//
//接下来 $m$ 行，每行三个整数 $u, v, w$。
//
//- 若 $w \geq 0$，则表示存在一条从 $u$ 至 $v$ 边权为 $w$ 的边，还存在一条从 $v$ 至 $u$ 边权为 $w$ 的边。
//- 若 $w < 0$，则只表示存在一条从 $u$ 至 $v$ 边权为 $w$ 的边。
//
//## 输出格式
//
//对于每组数据，输出一行一个字符串，若所求负环存在，则输出 `YES`，否则输出 `NO`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2
//3 4
//1 2 2
//1 3 4
//2 3 1
//3 1 -3
//3 3
//1 2 3
//2 3 4
//3 1 -8
//```
//
//### 输出 #1
//
//```
//NO
//YES
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//对于全部的测试点，保证：
//
//- $1 \leq n \leq 2 \times 10^3$，$1 \leq m \leq 3 \times 10^3$。
//- $1 \leq u, v \leq n$，$-10^4 \leq w \leq 10^4$。
//- $1 \leq T \leq 10$。
//
//#### 提示
//
//请注意，$m$ **不是**图的边数。

#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e3 + 10, M = 3e3 + 10;

int n, m;
int pos;

struct node
{
    int u, v, w;
}e[M * 2];

int dist[N];

bool bf()
{
    //初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    bool flag;
    for(int i = 1; i <= n; i++)
    {
        flag = false;

        for(int j = 1; j <= pos; j++)
        {
            int u = e[j].u, v = e[j].v, w = e[j].w;
            if(dist[u] == 0x3f3f3f3f) continue;

            if(dist[u] + w < dist[v])
            {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }

        if(flag == false) return flag;
    }

    return flag;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        cin >> n >> m;
        pos = 0; // 清空
        for(int i = 1; i <= m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            pos++;
            e[pos].u = u, e[pos].v = v, e[pos].w = w;
            
            if(w >= 0)
            {
                pos++;
                e[pos].u = v, e[pos].v = u, e[pos].w = w;
            }
        } 
        
        if(bf()) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
    
    return 0;
}
