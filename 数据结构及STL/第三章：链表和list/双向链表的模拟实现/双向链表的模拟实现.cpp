#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], pre[N], id, h;
int mp[N];

//��ӡ����
void print()
{
	for(int i = ne[h]; i; i = ne[i])
	{
		cout << e[i] << " ";	
	}	
	cout << endl << endl;
} 

//ͷ��
void push_front(int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	//���޸��½�������ָ��
	pre[id] = h;
	ne[id] = ne[h];
	//�޸��ڱ�λ��һ����������ָ��	
	pre[ne[h]] = id;
	ne[h] = id;
} 

//����
int find(int x)
{
	return mp[x];	
} 

//��ָ��λ��p�����һ����Ԫ��x
void insert_back(int p, int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = p;
	ne[id] = ne[p];
	pre[ne[p]] = id;
	ne[p] = id;	
} 

//��ָ��λ��p֮ǰ����һ����Ԫ��x
void insert_front(int p, int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = pre[p];
	ne[id] = p;
	ne[pre[p]] = id;
	pre[p] = id;	
} 

//ɾ��ָ��λ�õ�Ԫ��
void erase(int p)
{
	mp[e[p]] = 0;
		
	ne[pre[p]] = ne[p];
	pre[ne[p]] = pre[p];	
} 

int main()
{
	for(int i = 1; i <= 5; i++)
	{
		push_front(i);
		print();
	}
	
//	cout << find(1) << endl;
//	cout << find(2) << endl;
//	cout << find(6) << endl;
	
//	insert_back(2, 22);
//	print();
//	insert_back(3, 33);
//	print();
//	insert_back(4, 44);
//	print();

//	insert_front(2, 22);
//	print();
//	insert_front(3, 33);
//	print();
//	insert_front(4, 44);
//	print();

	erase(2);
	print();
	erase(4);
	print();
	
	return 0;
}
