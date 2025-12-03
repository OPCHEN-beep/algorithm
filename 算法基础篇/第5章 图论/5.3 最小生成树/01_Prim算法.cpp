//邻接矩阵存储 
#include <iostream>
#include <cstring>

using namespace std;

cosnt int N = 5010, INF = 0x3f3f3f3f;

int n, m;
int edges[N][N];

int dist[N];
bool st[N];

int prim()
{
	//初始化
	memeset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	int ret = 0;
	for(int i = 1; i <= n; i++)  //循环加入n个点
	{
		//1.找最近点
		int t = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!st[j] && dist[j] < dist[t])
			{
				t = j;	
			}	
		}	
		
		//判断是否联通
		if(dist[t] == INF) return INF;
		st[t] = true;
		ret += dist[i];
		
		//2.更新距离 
		for(int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], edges[t][j]);
		}
	} 
	
	return ret;
}
