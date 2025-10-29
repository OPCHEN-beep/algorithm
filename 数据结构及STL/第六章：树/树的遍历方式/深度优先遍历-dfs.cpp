//用vector数组实现 
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//vector<int> edges[N];//存储树
//bool st[N];//标记哪些点已经访问过了
//
//void dfs(int u)
//{
//	cout << u << " ";
//	st[u] = true;//当前这个点已经访问过了
//	
//	//访问所有的孩子
//	for(auto v : edges[u]) 
//	{
//		if(!st[v])
//		{
//			dfs(v);
//		}
//	}
// } 
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
//	//深度优先遍历
//	dfs(1); 
//	
//	return 0;
// } 


//链式前向星实现
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

//存树
int h[N], e[N], ne[N], id;
int n; 

void add(int a, int b)
{
	id++;
	e[id] = b;
	
	ne[id] = h[a];
	h[a] = id;
}

void dfs(int u)
{
	cout << u << " ";
	st[u] = true;
	
	for(int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if(!st[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	 //建树
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	} 
	
	//深度优先遍历
	dfs(1); 
	
	return 0;
 } 
