//����ַ��
#include <iostream>
#include <cstring> 
using namespace std;

const int N = 23;

int h[N];//��ϣ��
int e[N], ne[N], id;

//��ϣ����
int f(int x)
{
	return (x % N + N) % N;
}

//����Ԫ��
bool find(int x) 
{
	int idx = f(x);
	
	for(int i = h[idx]; i; i = ne[i])
	{
		if(e[i] == x) 
		{
			return true;
		}
		return false;
	}
 } 
 
 //���Ԫ�� + ��ϣ��ͻ
void insert(int x)
{
	if(find(x)) return;
	
	int idx = f(x);
	
	//ͷ����idx�ĺ���
	id++;
	e[id] = x;
	ne[id] = h[idx];
	h[idx] = id;
 } 

int main()
{
	int n; cin >> n;
	while(n--)
	{
		int op, x; cin >> op >> x;
		if(op == 1) // ��?
		{
			insert(x);
		} 
		
		else // ��ѯ
		{
			if(find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	} 
	return 0;
}
