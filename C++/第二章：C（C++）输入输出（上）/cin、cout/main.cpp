#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
//	int a = 123;
//	cout << a << endl;
//	
//	//设置字段宽度 
//	cout << setw(5) << a << endl;
//	cout << setw(10) << a << endl;
//	cout << setw(10) << setfill('*') << a << endl; 	//setfill填充空格
//	
//	double pi = 3.141592653589793;
//	cout << pi << endl;	//只打印五位 
//	//控制数值格式
//	//以固定小数点表示浮点数
//	cout << fixed << pi << endl;
//	//科学计数法形式
//	cout << scientific << pi << endl; 
//	//设置浮点数精度
//	cout << setprecision(2) << pi << endl; 
//	cout << fixed << setprecision(2) << pi << endl; 
	
	
	//控制整数格式
	//dec: 十进制
	//hex: 十六进制
	//oct：八进制
	int a = 15;
	cout << a << endl;
	cout << dec << a << endl; 
	cout << hex << a << endl; 
	cout << oct << a << endl; 
	
	
	//控制对齐方式
	int b = 123;
	cout << b << endl;
	cout << setw(10) << a << endl;
	cout << setw(10) << left << a << endl;	//左对齐 
	cout << setw(10) << right << a << endl;	//右对齐 
 	
	return 0; 
}
