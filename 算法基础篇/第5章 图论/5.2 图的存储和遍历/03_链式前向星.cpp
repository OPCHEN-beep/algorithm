#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//链式前向星
int h[N], e[N * 2], ne[N * 2], w[N * 2], id;
int n, m;

//把b头插到a所在的链表后面
void add(int a, int b, int c)
{
	id++;
	e[id] = b;
	w[id] = c;	//多存一个权值信息 
	ne[id] = h[a];
	h[a] = id;
 } 
 
 int main()
 {
 	cin >> n >> m;
 	for(int i = 1; i <= m; i++)
 	{
 		int a, b, c;
 		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c); 
	 }
 	
 	return 0;
 }
