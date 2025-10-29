//1139：整理药名
//
//时间限制: 1000 ms         内存限制: 65536 KB
//提交数:67591    通过数: 35830
//【题目描述】
//医生在书写药品名的时候经常不注意大小写，格式比较混乱。现要求你写一个程序将医生书写混乱的药品名整理成统一规范的格式，即药品名的第一个字符如果是字母要大写，其他字母小写。如将ASPIRIN、aspirin整理成Aspirin。
//
//【输入】
//第一行一个数字n，表示有n个药品名要整理，n不超过100。
//
//接下来n行，每行一个单词，长度不超过20，表示医生手书的药品名。药品名由字母、数字和-组成。
//
//【输出】
//n行，每行一个单词，对应输入的药品名的规范写法。
//
//【输入样例】
//4
//AspiRin
//cisapride
//2-PENICILLIN
//Cefradine-6
//【输出样例】
//Aspirin
//Cisapride
//2-penicillin
//Cefradine-6

#include <iostream>
#include <cstdio>
#include <ctype>
using namespace std;

const int N = 25;
char arr[N];

int main()
{
	int n = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		if(islower(arr[0]))
			arr[0] -= 32;
		int j = 1;
		while(arr[j])
		{
			if(isupper(arr[j]))
			{
				arr[j] += 32;
			}
			j++;
		}
		cout << arr << endl;
	}
	
	return 0;
} 
