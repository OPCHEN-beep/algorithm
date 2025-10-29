#include <iostream>
using namespace std;

const int N = 1e5 + 10;
//链式前向星
int h[N], e[N * 2], ne[N * 2], id;
int n; 

//其实就是把b头插到a所在的链表后面
void add(int a, int b)
{
	id++;
	e[id] = b;
	ne[id] = h[a];
	h[a] = id;
 } 

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		//a和b之间有一条边
		add(a, b);
		add(b, a); 
	}
	
	return 0;
}
