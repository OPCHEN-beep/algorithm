//离散化方式二：排序＋STL
//本质是和方式一一样的，只不过借助了STL，去重以及查找更方便
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];	//原始数据

int tmp[N]; //用来排序的数组
int cnt;
unordered_map<int ,int> id;//记录离散化之后的值

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		tmp[i] = x;	//数据放进离散化数组中	
	}	
	
	//离散化：排序 + 放进哈希表中
	sort(tmp + 1, tmp + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		if(id.count(tmp[i])) continue;	//如果已经存过这个数，就不做处理
		cnt++;	//这个数映射之后的值
		id[tmp[i]] = cnt;	//放进哈希表中 
	 } 
	 
	//找到离散化之后的值
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		cout << x << "离散化之后是：" << id[a[i]] << endl;	//二分查找离散化之后的值 
	 } 
	 
	return 0; 
 } 
