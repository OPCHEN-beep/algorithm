//# P3884 [JLOI2009] 二叉树问题
//
//## 题目描述
//
//如下图所示的一棵二叉树的深度、宽度及结点间距离分别为：
//
//- 深度：$4$
//- 宽度：$4$
//- 结点 8 和 6 之间的距离：$8$
//- 结点 7 和 6 之间的距离：$3$
//
//其中宽度表示二叉树上同一层最多的结点个数，节点 $u, v$ 之间的距离表示从 $u$ 到 $v$ 的最短有向路径上向根节点的边数的两倍加上向叶节点的边数。
//
//![](https://cdn.luogu.com.cn/upload/pic/6843.png)
//
//给定一颗以 1 号结点为根的二叉树，请求出其深度、宽度和两个指定节点 $x, y$ 之间的距离。
//
//## 输入格式
//
//第一行是一个整数，表示树的结点个数 $n$。  
//接下来 $n - 1$ 行，每行两个整数 $u, v$，表示树上存在一条连接 $u, v$ 的边。  
//最后一行有两个整数 $x, y$，表示求 $x, y$ 之间的距离。
//
//## 输出格式
//
//输出三行，每行一个整数，依次表示二叉树的深度、宽度和 $x, y$ 之间的距离。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10                                
//1 2                            
//1 3                            
//2 4
//2 5
//3 6
//3 7
//5 8
//5 9
//6 10
//8 6
//```
//
//### 输出 #1
//
//```
//4
//4
//8
//```
//
//## 说明/提示
//
//对于全部的测试点，保证 $1 \leq u, v, x, y \leq n \leq 100$，且给出的是一棵树。保证 $u$ 是 $v$ 的父结点。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 110;

int n;
vector<int> edges[N];

int fa[N];//i的父亲
int dist[N];//i到x的最短距离

//求深度
int dfs(int u)
{
    int ret = 0;
    for(auto v : edges[u])
    {
        ret = max(ret, dfs(v));
    }
    return ret + 1;
}

//求宽度
int bfs()
{
    queue<int> q;
    q.push(1);

    int ret = 0;

    while(q.size())
    {
        int sz = q.size();
        ret = max(ret, sz);

        while(sz--)
        {
            int u = q.front();
            q.pop();
            for(auto v : edges[u])
            {
                q.push(v);
            }
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);

        fa[v] = u;
    }

    //求深度
    cout << dfs(1) << endl;

    //求宽度
    cout << bfs() << endl;

    //求距离
    int x, y;
    cin >> x >> y;
    while(x != 1)
    {
        dist[fa[x]] = dist[x] + 1;
        x = fa[x];
    }

    int len = 0;
    while(y != 1 && dist[y] == 0)
    {
        len++;
        y = fa[y];
    }

    cout << dist[y] * 2 + len << endl;

    return 0;
}
