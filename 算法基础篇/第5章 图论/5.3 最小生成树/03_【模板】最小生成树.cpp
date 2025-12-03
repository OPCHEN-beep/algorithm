//# P3366 【模板】最小生成树
//
//## 题目描述
//
//如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 `orz`。
//
//## 输入格式
//
//第一行包含两个整数 $N,M$，表示该图共有 $N$ 个结点和 $M$ 条无向边。
//
//接下来 $M$ 行每行包含三个整数 $X_i,Y_i,Z_i$，表示有一条长度为 $Z_i$ 的无向边连接结点 $X_i,Y_i$。
//
//## 输出格式
//
//如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 `orz`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4 5
//1 2 2
//1 3 2
//1 4 3
//2 3 4
//3 4 3
//```
//
//### 输出 #1
//
//```
//7
//```
//
//## 说明/提示
//
//数据规模：
//
//对于 $20\%$ 的数据，$N\le 5$，$M\le 20$。
//
//对于 $40\%$ 的数据，$N\le 50$，$M\le 2500$。
//
//对于 $70\%$ 的数据，$N\le 500$，$M\le 10^4$。
//
//对于 $100\%$ 的数据：$1\le N\le 5000$，$1\le M\le 2\times 10^5$，$1\le Z_i \le 10^4$，$1\le X_i,Y_i\le N$。
//
//
//样例解释：
//
// ![](https://cdn.luogu.com.cn/upload/pic/2259.png) 
//
//所以最小生成树的总边权为 $2+2+3=7$。

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010,  M = 2e5 + 10, INF = 0x3f3f3f3f;

int n, m;
struct node
{
	int x, y, z;
}a[M];

int fa[N];  //并查集

bool cmp(node& a, node& b) 
{
	return a.z < b.z;
}

int find(int x)
{
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
 } 
 
 int kk()
 {
 	sort(a + 1, a + 1 + m, cmp);
 	int cnt = 0;
 	int ret = 0;
 	for(int i = 1; i <= m; i++)
 	{
 		int x = a[i].x, y = a[i].y, z = a[i].z;
 		
 		int fx = find(x), fy = find(y);
 		if(fx != fy)
 		{
 			cnt++;
 			ret += z;
 			fa[fx] = fy;
		 }
	 }
	 
	 return cnt == n - 1 ? ret : INF;
 }
 
 int main()
 {
 	cin >> n >> m;
 	for(int i = 1; i <= m; i++)
 	{
 		cin >> a[i].x >> a[i].y >> a[i].z;
	 }
	 
	 //初始化并查集 
	for(int i = 1; i <= n; i++) fa[i] = i;
	
	int ret = kk();
	
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl ;
 	
 	return 0;
 }
