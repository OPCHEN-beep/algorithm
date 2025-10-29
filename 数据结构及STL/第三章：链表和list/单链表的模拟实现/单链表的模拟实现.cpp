#include <iostream>

using namespace std;

const int N = 1e5 + 10;

//�������� 
int e[N], ne[N], h, id;
int mp[N];	//�������е�Ԫ�ر�ʾe[N]�����ж�ӦԪ�ص��±� 
//ͷ��
void push_front(int x)
{
	id++;
	e[id] = x;
	mp[x] = id; 
	
	//�����½��ָ��ͷ������һ��λ��
	//Ȼ����ͷ���ָ�������Ľ��
	ne[id] = ne[h];
	ne[h] = id;	
} 

//��ӡ����
void print()
{
	for(int i = ne[h]; i; i = ne[i])	
	{
		cout << e[i] << " ";
	}
	cout << endl << endl;
} 

//��ָ��λ��p������һ��x��ֵ
void insert(int p, int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	ne[id] = ne[p];
	ne[p] = id;
} 

//��ֵ���� 
int find(int x)
{
	//�ⷨһ����������
//	for(int i = ne[h]; i; i = ne[i])
//	{
//		if(e[i] == x)
//			return i;	
//	}	
//	return 0;

	//�ⷨ��������������
	return mp[x]; 
} 

//ɾ��ָ��λ��p֮�������
void erase(int p)
{
	if(ne[p])	//��p�������һ��Ԫ�ص�ʱ��
	{
		mp[e[ne[p]]] = 0;
		
		ne[p] = ne[ne[p]];	
	}	
} 

int main()
{
	for(int i = 1; i <= 5; i++)
	{
		push_front(i);	
		print();
	}	
	
//	insert(1, 9);
//	print();
//	insert(2, 100);
//	print();
	
//	cout << find(1) << endl;
//	cout << find(2) << endl;
//	cout << find(6) << endl;
	
	erase(2);
	print();
	erase(4);
	print();
	
	return 0;
} 
