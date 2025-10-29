//计算1~100之间3的倍数的数字之和 

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tmp = 0;
	for(int i = 1; i <= 100; i++)
	{
		if(i % 3 == 0)
			tmp += i;
	}
	printf("%d\n", tmp);
	
	return 0;
 } 
