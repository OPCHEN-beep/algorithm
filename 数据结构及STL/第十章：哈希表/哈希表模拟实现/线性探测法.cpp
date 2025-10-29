//线性探测法
#include <iostream>
#include <cstring>

using namespace std;

//N是质数 
const int N = 23, INF = 0x3f3f3f3f;

int h[N];//哈希表

//把哈希表中所有元素初始化为一个不会出现的值 
void init()
{
	memset(h, 0x3f, sizeof h);
}

//哈希函数
int f(int x)
{
	//模 加 模
	int idx = (x % N + N) % N;
	
	//处理冲突
	while(h[idx] != INF && h[idx] != x)
	{
		idx++;
		if(idx == N) idx = 0;
	 } 
	 return idx;
 } 
 
 //添加元素
 void insert(int x)
 {
 	int idx = f(x);
 	h[idx] = x;
  } 
  
//查找元素
bool find(int x)
{
	int idx = f(x);
	return h[idx] == x;
 } 

int main()
{
	init();
	int n;
	cin >> n;
	
	while(n--)
	{
		int op, x;
		cin >> op >> x;
		if(op == 1)
		{
			insert(x);
		}
		else
		{
			if(find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	
	return 0;
 } 
