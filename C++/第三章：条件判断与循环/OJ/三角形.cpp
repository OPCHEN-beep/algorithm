//2027：【例4.13】三角形
//
//时间限制: 1000 ms         内存限制: 65536 KB
//提交数:67700    通过数: 52691
//【题目描述】
//对于给定的自然数n(n<20)
//，在屏幕上输出仅由“*”构成的n
//行的直角三角形。
//
//【输入】
//输入n
//。
//
//【输出】
//题述三角形。
//
//【输入样例】
//5
//【输出样例】
//*
//**
//***
//****
//*****

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n = 0;
	cin >>n;
	for(int i = 1; i<= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cout << "*"; 
		}
		cout << endl;
	}
	
	return 0;
}
