//ͳ����������λ������OJ��:����һ����������������������Ǽ�λ���� 

#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n;
	do{
		n /= 10;
		m++;
	}while(n);
	printf("%d\n", m)
	
	return 0;
}
