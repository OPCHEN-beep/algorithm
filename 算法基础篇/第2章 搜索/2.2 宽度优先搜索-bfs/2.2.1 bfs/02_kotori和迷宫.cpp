//kotori和迷宫
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC50041
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//kotori在一个n*m迷宫里，迷宫的最外层被岩浆淹没，无法涉足，迷宫内有k个出口。kotori只能上下左右四个方向移动。她想知道有多少出口是她能到达的，最近的出口离她有多远？
//
//输入描述:
//第一行为两个整数n和m，代表迷宫的行和列数 (1≤n,m≤30)
//
//后面紧跟着n行长度为m的字符串来描述迷宫。'k'代表kotori开始的位置，'.'代表道路，'*'代表墙壁，'e'代表出口。保证输入合法。
//输出描述:
//若有出口可以抵达，则输出2个整数，第一个代表kotori可选择的出口的数量，第二个代表kotori到最近的出口的步数。（注意，kotori到达出口一定会离开迷宫）
//
//若没有出口可以抵达，则输出-1。
//示例1
//输入
//复制
//6 8
//e.*.*e.*
//.**.*.*e
//..*k**..
//***.*.e*
//.**.*.**
//*......e
//输出
//复制
//2 7
//说明
//可供选择坐标为[4,7]和[6,8]，到kotori的距离分别是8和7步。

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 35;

int n, m, x, y;
char a[N][N];
int dist[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs()
{
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    q.push({x, y});
    dist[x][y] = 0;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        int i = t.first, j = t.second;
        for(int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '*' && dist[x][y] == -1)
            {
                dist[x][y] = dist[i][j] + 1;
                
                if(a[x][y] == 'e')
                {
                    continue;
                }
                q.push({x, y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'k')
            {
                x = i;
                y = j;
            }
        }
    }
    
    bfs();
    
    //统计结果
    int cnt = 0, ret = 1e9;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 'e' && dist[i][j] != -1)
            {
                cnt++;
                ret = min(ret, dist[i][j]);
            }
        }
    }
    
    if(cnt == 0) cout << -1 << endl;
    else cout << cnt << " " << ret << endl;
    
    return 0;
}
