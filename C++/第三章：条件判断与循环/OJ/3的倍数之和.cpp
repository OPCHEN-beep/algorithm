//����1~100֮��3�ı���������֮�� 

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
