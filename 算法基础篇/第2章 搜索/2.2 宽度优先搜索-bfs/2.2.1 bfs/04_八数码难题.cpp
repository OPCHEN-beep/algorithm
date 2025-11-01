//# P1379 八数码难题
//
//## 题目描述
//
//在 $3\times 3$ 的棋盘上，摆有八个棋子，每个棋子上标有 $1$ 至 $8$ 的某一数字。棋盘中留有一个空格，空格用 $0$ 来表示。空格周围的棋子可以移到空格中。要求解的问题是：给出一种初始布局（初始状态）和目标布局（为了使题目简单,设目标状态为 $123804765$），找到一种最少步骤的移动方法，实现从初始布局到目标布局的转变。
//
//## 输入格式
//
//输入初始状态，一行九个数字，空格用 $0$ 表示。
//
//## 输出格式
//
//只有一行，该行只有一个数字，表示从初始状态到目标状态需要的最少移动次数。保证测试数据中无特殊无法到达目标状态数据。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//283104765
//```
//
//### 输出 #1
//
//```
//4
//```
//
//## 说明/提示
//
//### 样例解释
//
//![](https://cdn.luogu.com.cn/upload/image_hosting/7rhxbnup.png)
//
//图中标有 $0$ 的是空格。绿色格子是空格所在位置，橙色格子是下一步可以移动到空格的位置。如图所示，用四步可以达到目标状态。
//
//并且可以证明，不存在更优的策略。

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

string s;
string aim = "123804765";
unordered_map<string, int> dist;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs()
{
    queue<string> q;
    q.push(s);
    dist[s] = 0;

    while(q.size())
    {
        string t = q.front();
        q.pop();
        
        int pos = 0;
        while(t[pos] != '0') pos++;
        int x = pos / 3, y = pos % 3;  //计算二维矩阵

        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a <= 2 && b >= 0 && b <= 2)
            {
                string next = t;
                //（x, y）与 （a, b）做交换
                int p = 3 * a + b;
                swap(next[p], next[pos]);
                if(dist.count(next)) continue;

                dist[next] = dist[t] + 1;
                q.push(next);

                if(next == aim) return;  //剪枝
            }
        }
    }
}

int main()
{
    cin >> s;

    bfs();

    cout << dist[aim] << endl;
    
    return 0;
}
