#include <iostream>
using namespace std;

const int N = 1e5 + 10;
//��ʽǰ����
int h[N], e[N * 2], ne[N * 2], id;
int n; 

//��ʵ���ǰ�bͷ�嵽a���ڵ��������
void add(int a, int b)
{
	id++;
	e[id] = b;
	ne[id] = h[a];
	h[a] = id;
 } 

int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		//a��b֮����һ����
		add(a, b);
		add(b, a); 
	}
	
	return 0;
}
