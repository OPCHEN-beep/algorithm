#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//创建链表 
int e[N], ne[N], h, id;
int mp[N];	//该数组中的元素表示e[N]数组中对应元素的下标 
//头插
void push_front(int x)
{
	id++;
	e[id] = x;
	mp[x] = id; 
	
	//先让新结点指向头结点的下一个位置
	//然后让头结点指向新来的结点
	ne[id] = ne[h];
	ne[h] = id;	
} 

//打印链表
void print()
{
	for(int i = ne[h]; i; i = ne[i])	
	{
		cout << e[i] << " ";
	}
	cout << endl << endl;
} 

//在指定位置p处插入一个x的值
void insert(int p, int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	ne[id] = ne[p];
	ne[p] = id;
} 

//按值查找 
int find(int x)
{
	//解法一：遍历链表
//	for(int i = ne[h]; i; i = ne[i])
//	{
//		if(e[i] == x)
//			return i;	
//	}	
//	return 0;

	//解法二：创建新数组
	return mp[x]; 
} 

//删除指定位置p之后的数据
void erase(int p)
{
	if(ne[p])	//当p不是最后一个元素的时候
	{
		mp[e[ne[p]]] = 0;
		
		ne[p] = ne[ne[p]];	
	}	
} 

int main()
{
	for(int i = 1; i <= 5; i++)
	{
		push_front(i);	
		print();
	}	
	
//	insert(1, 9);
//	print();
//	insert(2, 100);
//	print();
	
//	cout << find(1) << endl;
//	cout << find(2) << endl;
//	cout << find(6) << endl;
	
	erase(2);
	print();
	erase(4);
	print();
	
	return 0;
} 
