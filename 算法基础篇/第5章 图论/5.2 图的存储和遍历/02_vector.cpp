#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, m;
vector<PII> edges[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({b, c});	//a、b之间有一条边，权值为c
		edges[b].push_back({a, c});	//无向边s 
	}
	
	return 0;
}
