#include <iostream>

using namespace std;

const int N = 1e6 + 10;	//根据实际情况而定


class SqList
{
	int a[N];	//用足够大的数组来模拟实现顺序表
	int n;		//标记顺序表里面有多少个元素
	
	public:
		//构造函数
		SqList()
		{
			n = 0;
		} 
		
		//尾插
		void push_back(int x)
		{
			a[++n] = x;
		} 
		
		//打印顺序表
		void print() 
		{
			for(int i = 1; i <= n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}


		//头插
		void push_front(int x)
		{
			//1.先把[1, n]的元素统一向后移动一位
			for(int i = n; i >= 1; i--)
			{
				a[i + 1] = a[i];
			}
			//2.把x放在表头
			a[1] = x;
			n++; 
		} 


		//任意位置插入
		void insert(int p, int x)
		{
			for(int i = n; i >= p; i--)
			{
				a[i + 1] = a[i];	
			}
			a[p] = x;
			n++;
		} 


		//尾删
		void pop_back()
		{
			n--;	
		} 


		//头删
		void pop_front()
		{
			for(int i = 2; i <= n; i++)
			{
				a[i - 1] = a[i];
			}
			n--;
		} 


		//任意位置删除数据
		void erase(int p)
		{
			for(int i = p + 1; i <= n; i++)
			{
				a[i - 1] = a[i];	
			}
			n--;
		} 


		//按值查找
		int find(int x)
		{
			for(int i  = 1; i <= n; i++)
			{
				if(i == x)
					return i;	
			}	
			return 0;
		} 


		//按位查找
		int at(int p)
		{
			return a[p];
		} 


		//按位修改
		int change(int p, int x)
		{
			a[p] = x;
 		} 


		//清空顺序表
		void clear()
		{
			n = 0;
 		} 	
};



//int main()
//{
	//测试尾插
//	push_back(1);
//	print();
//	push_back(2);
//	print(); 
//	push_back(3);
//	print();
//	push_back(4);
//	print();
//	push_back(5);
//	print();
//	push_back(6);
//	print();
//	push_back(7);
//	print();
//	push_back(8);
//	print();
//	push_back(9);
//	print();
//	push_back(10);
//	print();

//	//测试头插 
//	push_front(1);
//	print();
//	push_front(2);
//	print(); 
//	push_front(3);
//	print();
//	push_front(4);
//	print();
//	
//	insert(3, 10);
//	print();
//	
//	//测试尾删
//	cout << "尾删：" << endl;
//	pop_back();
//	print(); 
//	
//	//测试头删 
//	cout << "头删：" << endl;
//	pop_front();
//	print();
//	
//	//测试删除任意位置数据
//	cout << "删除任意位置数据：" << endl;
//	erase(3);
//	print();
//	erase(3);
//	print();
//
//	for(int i = 1; i <= 10; i++)
//	{
//		cout << "查找" << i << ":";
//		cout << find(i) << endl;
//		
//	}
//
//
//	
//	return 0;
// } 


int main()
{
	
	SqList s1, s2;
	for(int i = 1; i <= 5; i++)
	{
		s1.push_back(i);
		s2.push_back(i * 2);
	} 
	
	s1.print();
	s2.print();
	
	return 0;
}
