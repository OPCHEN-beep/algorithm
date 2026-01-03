//移棋子游戏
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC50616
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//给定一个有N个节点的有向无环图，图中某些节点上有棋子，两名玩家交替移动棋子。
//玩家每一步可将任意一颗棋子沿一条有向边移动到另一个点，无法移动者输掉游戏。
//对于给定的图和棋子初始位置，双方都会采取最优的行动，询问先手必胜还是先手必败。
//输入描述:
//第一行，三个整数N,M,K，N表示图中节点总数，M表示图中边的条数，K表示棋子的个数。
//接下来M行，每行两个整数X,Y表示有一条边从X出发指向Y。
//接下来一行，K个空格间隔的整数，表示初始时，棋子所在的节点编号。
//输出描述:
//若先手胜，输出win，否则输出lose。
//示例1
//输入
//复制
//6 8 4
//2 1
//2 4
//1 4
//1 5
//4 5
//1 3
//3 5
//3 6
//1 2 4 6
//输出
//复制
//win
//备注:
//对于全部数据，
//N
//≤
//2000
//,
//M
//≤
//6000
//,
//1
//≤
//K
//≤
//N
//N≤2000,M≤6000,1≤K≤N。

#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 2010;

int n, m, k;
vector<int> edges[N];

int f[N];

int sg(int u)
{
    if(f[u] != -1) return f[u];
    
    unordered_set<int> mp;
    for(int v : edges[u]) mp.insert(sg(v));
    
    for(int i = 0; ; i++)
        if(!mp.count(i))
            return f[u] = i;
}

int main()
{
    cin >> n >> m >> k;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    
    memset(f, -1, sizeof f);
    
    int ret = 0;
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        ret ^= sg(x);
    }
    
    if(ret) cout << "win" << endl;
    else cout << "lose" << endl;
    
    return 0;
}
