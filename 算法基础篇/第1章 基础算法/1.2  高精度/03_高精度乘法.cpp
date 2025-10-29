//# P1303 A*B Problem
//
//## 题目背景
//
//高精度乘法模板题。
//
//## 题目描述
//
//给出两个非负整数，求它们的乘积。
//
//## 输入格式
//
//输入共两行，每行一个非负整数。
//
//## 输出格式
//
//输出一个非负整数表示乘积。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1 
//2
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 说明/提示
//
//每个非负整数不超过 $10^{2000}$。

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], b[N], c[N];
int la, lb, lc;

//高精度乘法的模版 - c = a * b
void mul(int c[], int a[], int b[])
{
    //无进位相乘， 然后相加
    for(int i = 0; i < la; i++)
    {
        for(int j = 0; j < lb; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    //处理进位
    for(int i = 0; i < lc; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    //处理前导零
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
    string x, y;
	cin >> x >> y;
	
	//1.拆分每一位，逆序放在数组中
	la = x.size(); lb = y.size(); lc = la + lb;
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	
	//2.模拟乘法的过程
	mul(c, a, b);	//c = a + b
	
	//输出结果
	for(int i = lc - 1; i >= 0; i--) cout << c[i];

    return 0;
}
