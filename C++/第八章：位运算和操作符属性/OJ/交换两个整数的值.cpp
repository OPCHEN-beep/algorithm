//交换两个整数的值 (不允许创建临时变量)
#include <iostream>
using namespace std;


int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	//交换
	cout << "交换前：" << "a = " << a << " " << "b = " << b << endl;
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	cout << "交换后：" << "a = " << a << " " << "b = " << b << endl;
 	
	return 0;
}
