//# P4554 小明的游戏
//
//## 题目描述
//
//小明最近喜欢玩一个游戏。给定一个 $n \times m$ 的棋盘，上面有两种格子 `#` 和 `@`。游戏的规则很简单：给定一个起始位置和一个目标位置，小明每一步能向上，下，左，右四个方向移动一格。如果移动到同一类型的格子，则费用是 $0$，否则费用是 $1$。请编程计算从起始位置移动到目标位置的最小花费。
//
//## 输入格式
//
//输入文件有多组数据。   
//输入第一行包含两个整数 $n$，$m$，分别表示棋盘的行数和列数。   
//输入接下来的 $n$ 行，每一行有 $m$ 个格子（使用 `#` 或者 `@` 表示）。   
//输入接下来一行有四个整数 $x_1, y_1, x_2, y_2$，分别为起始位置和目标位置。   
//当输入 $n$，$m$ 均为 $0$ 时，表示输入结束。
//
//## 输出格式
//
//对于每组数据，输出从起始位置到目标位置的最小花费。每一组数据独占一行。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 2
//@#
//#@
//0 0 1 1
//2 2
//@@
//@#
//0 1 1 0
//0 0
//```
//
//### 输出 #1
//
//```
//2
//0
//```
//
//## 说明/提示
//
//对于20%的数据满足：$1 \le n, m \le 10$。   
//对于40%的数据满足：$1 \le n, m \le 300$。   
//对于100%的数据满足：$1 \le n, m \le 500$。

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

const int N = 510;

int n, m, x1, y1, x2, y2;
char g[N][N];
int dist[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs()
{
    if(x1 == x2 && y1 == y2) return 0;

    memset(dist, -1, sizeof dist);
    deque<pair<int, int>> q;
    q.push_back({x1, y1});
    dist[x1][y1] = 0;

    while(q.size())
    {
        auto [a, b] = q.front(); q.pop_front();

        for(int i = 0; i < 4; i++)
        {
            int x = a + dx[i], y = b + dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= m && dist[x][y] == -1)
            {
                char prev = g[a][b], cur = g[x][y];
                if(prev == cur) //边权是0
                {
                    q.push_front({x, y});
                    dist[x][y] = dist[a][b];
                }
                else //边权是1
                {
                    q.push_back({x, y});
                    dist[x][y] = dist[a][b] + 1;
                }

                if(x == x2 && y == y2) return dist[x2][y2];
            }
        }
    }
    return -1;
}

int main()
{
    while(cin >> n >> m)
    {
        if(!n && !m) break;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> g[i][j];
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;

        cout << bfs() << endl;
    }

    return 0;
}
