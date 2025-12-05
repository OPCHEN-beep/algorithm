#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10, INF = 2147483647;

int n, m, s;
vector<PII> edges[N];

int dist[N];

void bf()
{
	for(int i = 0; i <= n; i++) dist[i] = INF;
	dist[s] = 0;
	
	bool flag = false;
	for(int u = 1; i < n; i++)
	{
		flag = false;  // 判断是否进行了松弛操作
		for(int u = 1; u <= n; u++)
		{
			if(dist[u] == INF) continue;
			
			for(auto& t : edges[u])
			{
				int v = t.first, w = t.second;
				if(dist[u] + w < dist[v])
				{
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		if(flag == false) break;
	}
	
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
 } 
 
 int main()
 {
 	cin >> n >> m >> s;
 	for(int i = 1; i <= m; i++)
 	{
 		int u, v, w;
 		cin >> u >> v >> w;
 		edges[u].push_back({v, w});
	 }
	 
	 bf();
	 
	 return 0;
 }
