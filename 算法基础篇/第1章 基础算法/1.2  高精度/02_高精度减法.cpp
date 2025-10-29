//# P2142 高精度减法
//
//## 题目描述
//
//高精度减法。
//
//## 输入格式
//
//两个整数 $a,b$（第二个可能比第一个大）。
//
//## 输出格式
//
//结果（是负数要输出负号）。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2
//1
//```
//
//### 输出 #1
//
//```
//1
//```
//
//## 说明/提示
//
//- $20\%$ 数据 $a,b$ 在 long long 范围内；
//- $100\%$ 数据 $0<a,b\le 10^{10086}$。

#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1e6 + 10;

int a[N], b[N], c[N];
int la, lb, lc;

//比大小
bool cmp(string& x, string& y)
{
    //先比较长度
    if(x.size() != y.size()) return x.size() < y.size();

    //再按照 “字典序” 的方式比较
    return x < y;
}

//高精度减法的模版 - c = a - b
void sub(int c[], int a[], int b[])
{
    for(int i = 0; i < lc; i++)
    {
        c[i] += a[i] - b[i];//对应位相减，然后处理错位
        if(c[i] < 0)
        {
            c[i + 1] -= 1;//错位
            c[i] += 10;
        }
    }
    //处理前导零
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
	string x, y;
	cin >> x >> y;

    //比大小
    if(cmp(x, y))
    {
        swap(x, y);
        cout << '-';
    }
	
	//1.拆分每一位，逆序放在数组中
	la = x.size(); lb = y.size(); lc = max(la, lb);
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	
	//2.模拟减法的过程
	sub(c, a, b);	//c = a + b
	
	
	//输出结果
	for(int i = lc - 1; i >= 0; i--) cout << c[i];
	
	return 0;
 } 
