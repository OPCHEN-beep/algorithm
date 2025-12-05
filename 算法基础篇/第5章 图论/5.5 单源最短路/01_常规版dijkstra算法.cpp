#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int N = 1e4 + 10, INF = 2147483647;

int n, m, s;

vector<PII> edges[N];

LL dist[N];
bool st[N];

void dijkstra()
{
	for(int i = 0; i <= n; i++) dist[i] = INF;
	dist[s] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		int u = 0;
		for(int j = 1; j <= n; j++)
		{
			int u = 0;
			for(int j = 1; j <= n; j++)
			{
				if(!st[j] && dist[j] < dist[u]) u = j;
			}
		}
					
		st[u] = true;
			
		for(auto& t : edges[u])
		{
			int v = t.first, w = t.second;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
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
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
	}
	
	dijkstra();
	
	return 0;
}


