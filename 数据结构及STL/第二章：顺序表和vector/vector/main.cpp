#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

struct node
{
	int a, b;
	string s;
};

void print(vector<int>& a)	//传引用，不需要拷贝 
{
	//利用size遍历 
//	for(int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;

	//利用迭代器遍历
//	for(auto it = a.begin(); it != a.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;

	//使用范围for	--- 存在迭代器就可以使用 
	for(auto x: a)
	{
		cout << x << " ";	
	} 
	cout << endl;
}

int main()
{
	//1.创建vector
	vector<int> a1;			//创建一个名字为a1的空的可变长数组，里面的数据都是int类型
	vector<int> a2(N);  	//创建一个名字为a2的大小为10的可变长数组，里面的数据都是int类型
	vector<int> a3(N, 2);	//创建一个大小为10的可变长数组，里面的值都初始化为2
	vector<int> a4 = {1, 2, 3, 4, 5};//初始化列表的创建方式
	//<>可以存放任意的数据类型 ，甚至是STL本身。
	vector<string> a5;//存字符串
	vector<node> a6;  //存结构体
	vector<vector<int>> a7;//创建一个二维的可变长数组
	vector<int> a8[N];	//创建一个大小为N的vector数组（元素都是vector，为二维） 
	
	
	//2.size和empty
//	print(a2);
//	print(a3);
//	print(a4);
//	if(a1.empty())
//		cout << "空" << endl;
		
	//3.begin和end
//	print(a2);
//	print(a3);
//	print(a4);
	
	//4.push_back和pop_back
//	for(int i = 0; i < 5; i++)
//	{
//		a1.push_back(i);
//		print(a1);
//	}
//	while(!a1.empty())
//	{
//		print(a1);
//		a1.pop_back();
//	}

	//5.front\back
//	cout << a4.front() << " " << a4.back() << endl;	
	
	//6.resize
	vector<int> aa(5, 1);
	print(aa);
	
	//扩大成10
	aa.resize(10);
	print(aa);
	//缩小成3
	aa.resize(3);
	print(aa); 
	
	//7.clear
	cout << aa.size() << endl;
	aa.clear();
	cout << aa.size() << endl;	
	
	return 0;
}
