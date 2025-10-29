//# P1601 A+B Problem（高精）
//
//## 题目描述
//
//高精度加法，相当于 a+b problem，**不用考虑负数**。
//
//## 输入格式
//
//分两行输入。$a,b \leq 10^{500}$。
//
//## 输出格式
//
//输出只有一行，代表 $a+b$ 的值。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1
//1
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//1001
//9099
//```
//
//### 输出 #2
//
//```
//10100
//```
//
//## 说明/提示
//
//$20\%$ 的测试数据，$0\le a,b \le10^9$；
//
//$40\%$ 的测试数据，$0\le a,b \le10^{18}$。

#include <iostream>
#include <string>

using namespace std;

const int N = 1e6 + 10;

int a[N], b[N], c[N];
int la, lb, lc;

//高精度加法的模版 - c = a + b 
void add(int c[], int a[], int b[])
{
	for(int i = 0; i < lc; i++)
	{
		c[i] += a[i] + b[i];	//对应位相加， 再加上进位
		c[i + 1] += c[i] / 10;	//处理进位
		c[i] %= 10;	
	}	
	
	if(c[lc]) lc++;
} 

int main()
{
	string x, y;
	cin >> x >> y;
	
	//1.拆分每一位，逆序放在数组中
	la = x.size(); lb = y.size(); lc = max(la, lb);
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	
	//2.模拟加法的过程
	add(c, a, b);	//c = a + b
	
	
	//输出结果
	for(int i = lc - 1; i >= 0; i--) cout << c[i];
	
	return 0;
 } 
