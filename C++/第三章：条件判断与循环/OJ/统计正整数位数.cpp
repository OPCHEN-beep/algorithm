//统计正整数的位数（非OJ）:输入一个正整数，计算这个整数是几位数？ 

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
