//# P3371 【模板】单源最短路径（弱化版）
//
//## 题目背景
//
//本题测试数据为随机数据，在考试中可能会出现构造数据让 SPFA 不通过，如有需要请移步 [P4779](https://www.luogu.org/problemnew/show/P4779)。
//
//## 题目描述
//
//如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。
//
//## 输入格式
//
//第一行包含三个整数 $n,m,s$，分别表示点的个数、有向边的个数、出发点的编号。
//
//接下来 $m$ 行每行包含三个整数 $u,v,w$，表示一条 $u \to v$ 的，长度为 $w$ 的边。
//
//## 输出格式
//
//输出一行 $n$ 个整数，第 $i$ 个表示 $s$ 到第 $i$ 个点的最短路径，若不能到达则输出 $2^{31}-1$。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4 6 1
//1 2 2
//2 3 2
//2 4 1
//1 3 5
//3 4 3
//1 4 4
//```
//
//### 输出 #1
//
//```
//0 2 4 3
//```
//
//## 说明/提示
//
//【数据范围】    
//对于 $20\%$ 的数据：$1\le n \le 5$，$1\le m \le 15$；  
//对于 $40\%$ 的数据：$1\le n \le 100$，$1\le m \le 10^4$；   
//对于 $70\%$ 的数据：$1\le n \le 1000$，$1\le m \le 10^5$；   
//对于 $100\%$ 的数据：$1 \le n \le 10^4$，$1\le m \le 5\times 10^5$，$1\le u,v\le n$，$w\ge 0$，$\sum w< 2^{31}$，保证数据随机。
//
//**Update 2022/07/29：两个点之间可能有多条边，敬请注意。**
//
//对于真正 $100\%$ 的数据，请移步 [P4779](https://www.luogu.org/problemnew/show/P4779)。请注意，该题与本题数据范围略有不同。
//
//
//样例说明：
//
//![](https://cdn.luogu.com.cn/upload/pic/7641.png)
//
//图片 1 到 3 和 1 到 4 的文字位置调换

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m, s;

vector<PII> edges[N];

int dist[N];
bool st[N];

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;  //小根堆
	
	heap.push({0, s});
	dist[s] = 0; 
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int u = t.second;
		
		if(st[u]) continue;
		st[u] = true;
		
		for(auto& t : edges[u])
		{
			int v = t.first, w = t.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				heap.push({dist[v], v});
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << dist[i] << " ";
	}
}

int main()
{
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edges[x].push_back({y, z});
	}
	
	dijkstra();
	
	return 0;
}
