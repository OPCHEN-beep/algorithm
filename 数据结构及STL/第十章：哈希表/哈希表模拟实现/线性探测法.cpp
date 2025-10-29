//����̽�ⷨ
#include <iostream>
#include <cstring>

using namespace std;

//N������ 
const int N = 23, INF = 0x3f3f3f3f;

int h[N];//��ϣ��

//�ѹ�ϣ��������Ԫ�س�ʼ��Ϊһ��������ֵ�ֵ 
void init()
{
	memset(h, 0x3f, sizeof h);
}

//��ϣ����
int f(int x)
{
	//ģ �� ģ
	int idx = (x % N + N) % N;
	
	//�����ͻ
	while(h[idx] != INF && h[idx] != x)
	{
		idx++;
		if(idx == N) idx = 0;
	 } 
	 return idx;
 } 
 
 //���Ԫ��
 void insert(int x)
 {
 	int idx = f(x);
 	h[idx] = x;
  } 
  
//����Ԫ��
bool find(int x)
{
	int idx = f(x);
	return h[idx] == x;
 } 

int main()
{
	init();
	int n;
	cin >> n;
	
	while(n--)
	{
		int op, x;
		cin >> op >> x;
		if(op == 1)
		{
			insert(x);
		}
		else
		{
			if(find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	
	return 0;
 } 
