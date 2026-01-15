//# P4537 [CQOI2007] 矩形
//
//## 题目描述
//
//给一个 $a\times b$ 矩形，由 $a\times b$ 个单位正方形组成。你需要沿着网格线把它分成非空的两部分，每部分所有格子连通，且至少有一个格子在原矩形的边界上。“连通”是指任两个格子都可以通过水平或者竖直路径连在一起。 求方案总数。例如 $3\times 2$ 的矩形有 $15$ 种方案。
//
//![](https://cdn.luogu.com.cn/upload/pic/18502.png)
//
//## 输入格式
//
//输入仅一行，为两个整数 $a,b$（$1 \le a \le 6$，$2 \le b \le7$）。
//
//## 输出格式
//
//输出仅一行，即方案总数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 2
//```
//
//### 输出 #1
//
//```
//15
//```

#include <iostream>

using namespace std;

const int N = 10;

int n, m;
bool st[N][N];
int ret;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j)
{
    if(i < 1 || i >= n || j < 1 || j >= m)
    {
        ret++;
        return;
    }

    st[i][j] = true;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];

        if(!st[x][y]) dfs(x, y);
    }
    st[i][j] = false;
}

int main()
{
    cin >> n >> m;

    for(int j = 1; j < m; j++)
    {
        st[0][j] = true;
        dfs(1, j);
        st[0][j] = false;
    }

    for(int i = 1; i < n; i++)
    {
        st[i][0] = true;
        dfs(i, 1);
        st[i][0] = false;
    }
    cout << ret << endl;
    
    return 0;
}
