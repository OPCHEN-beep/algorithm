//# P1596 [USACO10OCT] Lake Counting S
//
//## 题目描述
//
//由于最近的降雨，水在农夫约翰的田地里积聚了。田地可以表示为一个 $N \times M$ 的矩形（$1 \leq N \leq 100$；$1 \leq M \leq 100$）。每个方格中要么是水（`W`），要么是干地（`.`）。农夫约翰想要弄清楚他的田地里形成了多少个水塘。一个水塘是由连通的水方格组成的，其中一个方格被认为与它的八个邻居相邻。给定农夫约翰田地的示意图，确定他有多少个水塘。
//
//## 输入格式
//
//第 $1$ 行：两个用空格分隔的整数：$N$ 和 $M$。
//
//第 $2$ 行到第 $N+1$ 行：每行 $M$ 个字符，表示农夫约翰田地的一行。
//
//每个字符要么是 `W`，要么是 `.`。
//
//字符之间没有空格。
//
//## 输出格式
//
//第 $1$ 行：农夫约翰田地中的水塘数量。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10 12
//W........WW.
//.WWW.....WWW
//....WW...WW.
//.........WW.
//.........W..
//..W......W..
//.W.W.....WW.
//W.W.W.....W.
//.W.W......W.
//..W.......W.
//```
//
//### 输出 #1
//
//```
//3
//```
//
//## 说明/提示
//
//输出详情：共有三个水塘：一个在左上角，一个在左下角，还有一个沿着右侧。
//
//（由 ChatGPT 4o 翻译）

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
char g[N][N];
bool st[N][N];

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1 ,1, -1};

void bfs(int i, int j)
{
    queue<pair<int , int>> q;
    q.push({i, j});
    st[i][j] = true;

    while(q.size())
    {
        auto [a, b] = q.front(); q.pop();
        for(int k = 0; k < 8; k++)
        {
            int x = a + dx[k], y = b + dy[k];
            if(x < 1 || x > n || y < 1 || y > m) continue;
            if(st[x][y] || g[x][y] == '.') continue;

            st[x][y] = true;
            q.push({x, y});
        }
    }
}

void dfs(int i, int j)
{
    st[i][j] = true;

    for(int k = 0; k < 8; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if(x < 1 || x > n || y < 1 || y > m) continue;
        if(st[x][y] || g[x][y] == '.') continue;

        dfs(x, y);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            //发现一个没有搜索过的w
            if(g[i][j] == 'W' && !st[i][j])
            {
                ret++;
                //bfs(i, j);
                dfs(i, j);
            }
        }
    }

    cout << ret << endl;
    
    return 0;
}
