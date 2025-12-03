//# P2573 [SCOI2012] 滑雪
//
//## 题目描述
//
//a180285 非常喜欢滑雪。他来到一座雪山，这里分布着 $m$ 条供滑行的轨道和 $n$ 个轨道之间的交点（同时也是景点），而且每个景点都有一编号 $i\space (1 \le i \le n)$ 和一高度 $h_i$。  
//
//a180285 能从景点 $i$ 滑到景点 $j$ 当且仅当存在一条 $i$ 和 $j$ 之间的边，且 $i$ 的高度**不小于** $j$。与其他滑雪爱好者不同，a180285 喜欢用最短的滑行路径去访问尽量多的景点。如果仅仅访问一条路径上的景点，他会觉得数量太少。
//
//于是 a180285 拿出了他随身携带的时间胶囊。这是一种很神奇的药物，吃下之后可以立即回到上个经过的景点（不用移动也不被认为是 a180285 滑行的距离）。  
//
//请注意，这种神奇的药物是可以连续食用的，即能够回到较长时间之前到过的景点（比如上上个经过的景点和上上上个经过的景点）。 现在，a180285 站在 $1$ 号景点望着山下的目标，心潮澎湃。他十分想知道在不考虑时间胶囊消耗的情况下，以最短滑行距离滑到尽量多的景点的方案（即满足经过景点数最大的前提下使得滑行总距离最小）。你能帮他求出最短距离和景点数吗？
//
//## 输入格式
//
//输入的第一行是两个整数 $n,m$。接下来一行有 $n$ 个整数 $h_i$，分别表示每个景点的高度。
//
//接下来 $m$ 行，表示各个景点之间轨道分布的情况。每行三个整数 $u,v,k$，表示编号为 $u$ 的景点和编号为 $v$ 的景点之间有一条长度为 $k$ 的轨道。
//
//## 输出格式
//
//输出一行，表示 a180285 最多能到达多少个景点，以及此时最短的滑行距离总和。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 3 
//3 2 1 
//1 2 1 
//2 3 1 
//1 3 10
//```
//
//### 输出 #1
//
//```
//3 2
//```
//
//## 说明/提示
//
//对于 $ 30\% $ 的数据，$ 1 \le n \le 2000 $；
//
//对于 $ 100\% $ 的数据，$ 1 \le n \le 10^5 , 1 \le m \le 10^6 , 1 \le h_i \le 10^9 , 1 \le k_i \le 10^9 $。

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int ,int> PII;
const int N = 1e5 + 10, M = 2e6 + 10;

int n, m;
int h[N];

vector<PII> edges[N];

int fa[N];

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

LL cnt, ret;
bool st[N];

int pos;
struct node
{
    int x, y, z;
}e[M];

void dfs(int u)
{
    cnt++;
    st[u] = true;

    for(auto& p : edges[u])
    {
        int v = p.first, k = p.second;
        pos++;
        e[pos].x = u;
        e[pos].y = v;
        e[pos].z = k;

        if(!st[v]) dfs(v);
    }
}

bool cmp(node& a, node& b)
{
    //先考虑高度，再考虑长度
    int y1 = a.y, z1 = a.z, y2 = b.y, z2 = b.z;

    if(h[y1] != h[y2]) return h[y1] > h[y2];
    else return z1 < z2;
}

void kk()
{
    for(int i = 1; i <= n; i++) fa[i] = i;

    sort(e + 1, e + 1 + pos, cmp);

    for(int i = 1; i <= pos; i++)
    {
        int x = e[i].x, y = e[i].y, z = e[i].z;

        int fx = find(x), fy = find(y);
        if(fx != fy)
        {
            ret += z;
            fa[fx] = fy;
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for(int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(h[x] >= h[y]) edges[x].push_back({y, z});
        if(h[x] <= h[y]) edges[y].push_back({x, z});
    }

    dfs(1);
    cout << cnt << " ";

    kk();
    cout << ret << endl;

    return 0;
}
