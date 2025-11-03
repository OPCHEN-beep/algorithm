//矩阵距离
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC51024
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//给定一个N行M列的01矩阵 A，A[i][j] 与 A[k][l] 之间的曼哈顿距离定义为：
//dist(A[i][j],A[k][l]) =|i-k|+|j-l|
//输出一个N行M列的整数矩阵B，其中：
//B
//[
//i
//]
//[
//j
//]
//=
//m
//i
//n
//(
//1
//≤
//x
//≤
//N
//,
//1
//≤
//y
//≤
//M
//,
//A
//[
//x
//]
//[
//y
//]
//=
//1
//)
//B[i][j]=min(1≤x≤N,1≤y≤M,A[x][y]=1)?{dist(A[i][j],A[x][y])}
//即求与每个位置曼哈顿距离最近的1
//N
//,
//M
//≤
//1000
//N,M≤1000
//
//
//
//输入描述:
//第一行两个整数n,m。
//接下来一个N行M列的01矩阵，数字之间没有空格。
//输出描述:
//一个N行M列的矩阵B，相邻两个整数之间用一个空格隔开。
//示例1
//输入
//复制
//3 4
//0001
//0011
//0110
//输出
//复制
//3 2 1 0
//2 1 0 0
//1 0 0 1

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, m;
char a[N][N];
int dist[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs()
{
    memset(dist, -1, sizeof dist);
    
    queue<PII> q;
    //1.所有的起点加入到队列里面
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
           if(a[i][j] == '1')
            {
                  q.push({i, j});
                  dist[i][j] = 0;
            }  
        }   
    }
    
    //2.正常的bfs
    while(q.size())
    {
        auto t = q.front(); q.pop();
        int x = t.first, y = t.second;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 1 && a <= n && b >= 1 && b <= m && dist[a][b] == -1)
            {
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
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
        }
    }
    
    bfs();
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
