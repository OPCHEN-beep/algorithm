//��������������ֵ (����������ʱ����)
#include <iostream>
using namespace std;


int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	//����
	cout << "����ǰ��" << "a = " << a << " " << "b = " << b << endl;
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	
	cout << "������" << "a = " << a << " " << "b = " << b << endl;
 	
	return 0;
}
