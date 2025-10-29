//离散化方式一：排序＋去重＋二分查找离散化后的值
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];	//原始数据

int pos;	//记录离散化数组中元素的个数
int disc[N];//离散化需要的数组

//二分查找离散化之后的值，其实就是排序之后的下标
int find(int x)
{
	int l = 1, r = pos;	//注意查找的区间
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(disc[mid] >= x) r = mid;
		else l = mid + 1;
	}	
	
	return l;
} 

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		disc[++pos] = x;	//数据放进离散化数组中 
	}
	
	//离散化：排序＋去重
	sort(disc + 1, disc + 1 + pos);
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);
	
	//找到离散化之后的值
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		cout << x << "离散化之后是：" << find(x) << endl;	//二分查找离散化之后的值	
	} 
	
	return 0;
}
