//链地址法
#include <iostream>
#include <cstring> 
using namespace std;

const int N = 23;

int h[N];//哈希表
int e[N], ne[N], id;

//哈希函数
int f(int x)
{
	return (x % N + N) % N;
}

//查找元素
bool find(int x) 
{
	int idx = f(x);
	
	for(int i = h[idx]; i; i = ne[i])
	{
		if(e[i] == x) 
		{
			return true;
		}
		return false;
	}
 } 
 
 //添加元素 + 哈希冲突
void insert(int x)
{
	if(find(x)) return;
	
	int idx = f(x);
	
	//头插在idx的后面
	id++;
	e[id] = x;
	ne[id] = h[idx];
	h[idx] = id;
 } 

int main()
{
	int n; cin >> n;
	while(n--)
	{
		int op, x; cin >> op >> x;
		if(op == 1) // 插?
		{
			insert(x);
		} 
		
		else // 查询
		{
			if(find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	} 
	return 0;
}
