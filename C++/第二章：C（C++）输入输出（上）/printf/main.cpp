#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	printf("%5d\n",123);
	
	printf("%-5d\n",1234567);
	
	printf("%.1f\n",123.45);
	
	printf("6.2f\n",0.5);	//6表示总宽度至少是6位，2表示小数点后只有2位。 
	
	printf("*.*f\n",6,2,0.5); 
	
	return 0;
 } 
