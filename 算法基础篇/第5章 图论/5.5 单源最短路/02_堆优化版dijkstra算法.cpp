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
	priority_queue<PII, vector<PII>, greater<PII>> heap;  //Ð¡¸ù¶Ñ
	
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
