//2039：【例5.6】冒泡排序
//
//时间限制: 1000 ms         内存限制: 65536 KB
//提交数:100179    通过数: 55556
//【题目描述】
//编程输入n(1≤n≤20)
//个小于1000
//非负整数，然后自动按从大到小的顺序输出。（冒泡排序）
//
//【输入】
//第一行，数的个数n
//;
//
//第二行，n
//个非负整数。
//
//【输出】
//由大到小的n
//个非负整数，每个数占一行。
//
//【输入样例】
//5
//2 5 8 6 12
//【输出样例】
//12
//8
//6
//5
//2

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 25;
int arr[N];


int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(arr[j] < arr[i])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + i] = tmp;
			} 
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	 } 
	 
	
	return 0;
 } 
