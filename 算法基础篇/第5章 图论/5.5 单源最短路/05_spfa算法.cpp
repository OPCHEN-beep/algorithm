#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

const int N = 1e4 + 10, INF = 2147483647;

int n, m, s;
vector<PII> edges[N];

int dist[N];
bool st[N]; // 标记哪些结点在队列中

void spfa()
{
	for(int i = 0; i <= n; i++) dist[i] = INF;
	
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	st[s] = true;
	
	while(q.size())
	{
		auto a = q.front(); q.pop();
		st[a] = false;
		
		for(auto& t : edges[a])
		{
			int b = t.first, c = t.second;
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
				if(!st[b])
				{
					q.push(b);
					st[b] = true;
				}
			}
		}
	} 
	
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
} 

int main()
{
	cin >> n >> m >> s;
	
	for(int i = 1; i <= m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back({b, c});
	} 
	
	spfa();
	
	return 0;
}

