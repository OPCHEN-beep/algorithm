////用vector数组实现
//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//vector<int> edges[N];
//bool st[N];
//
//void bfs()
//{
//	queue<int> q;
//	q.push(1);
//	st[1] = true;
//	
//	while(q.size())
//	{
//		int u = q.front();
//		q.pop();
//		cout << u << " ";
//		
//		for(auto v : edges[u])
//		{
//			if(!st[v])
//			{
//				q.push(v);
//				st[v] = true;
//			}
//		}
//	}
//}
//
//int main()
//{
//	//建树
//	cin >> n;
//	for(int i = 1; i < n; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);	
//	} 
//	
//	bfs();
//	
//	return 0;
// } 


//链式前向星
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n;
int h[N], e[N * 2], ne[N * 2], id; 
bool st[N];

void add(int a, int b)
{
	id++;
	e[id] = b;
	ne[id] = h[a];
	h[a] = id;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	st[1] = true; 
}

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	bfs();
	
	return 0;
}
