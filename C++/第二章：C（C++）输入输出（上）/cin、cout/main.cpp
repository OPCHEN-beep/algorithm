#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
//	int a = 123;
//	cout << a << endl;
//	
//	//�����ֶο�� 
//	cout << setw(5) << a << endl;
//	cout << setw(10) << a << endl;
//	cout << setw(10) << setfill('*') << a << endl; 	//setfill���ո�
//	
//	double pi = 3.141592653589793;
//	cout << pi << endl;	//ֻ��ӡ��λ 
//	//������ֵ��ʽ
//	//�Թ̶�С�����ʾ������
//	cout << fixed << pi << endl;
//	//��ѧ��������ʽ
//	cout << scientific << pi << endl; 
//	//���ø���������
//	cout << setprecision(2) << pi << endl; 
//	cout << fixed << setprecision(2) << pi << endl; 
	
	
	//����������ʽ
	//dec: ʮ����
	//hex: ʮ������
	//oct���˽���
	int a = 15;
	cout << a << endl;
	cout << dec << a << endl; 
	cout << hex << a << endl; 
	cout << oct << a << endl; 
	
	
	//���ƶ��뷽ʽ
	int b = 123;
	cout << b << endl;
	cout << setw(10) << a << endl;
	cout << setw(10) << left << a << endl;	//����� 
	cout << setw(10) << right << a << endl;	//�Ҷ��� 
 	
	return 0; 
}
