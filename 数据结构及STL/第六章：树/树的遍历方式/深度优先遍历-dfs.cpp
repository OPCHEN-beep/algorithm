//��vector����ʵ�� 
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//vector<int> edges[N];//�洢��
//bool st[N];//�����Щ���Ѿ����ʹ���
//
//void dfs(int u)
//{
//	cout << u << " ";
//	st[u] = true;//��ǰ������Ѿ����ʹ���
//	
//	//�������еĺ���
//	for(auto v : edges[u]) 
//	{
//		if(!st[v])
//		{
//			dfs(v);
//		}
//	}
// } 
//
//int main()
//{
//	//����
//	cin >> n;
//	for(int i = 1; i < n; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);	
//	} 
//	
//	//������ȱ���
//	dfs(1); 
//	
//	return 0;
// } 


//��ʽǰ����ʵ��
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

//����
int h[N], e[N], ne[N], id;
int n; 

void add(int a, int b)
{
	id++;
	e[id] = b;
	
	ne[id] = h[a];
	h[a] = id;
}

void dfs(int u)
{
	cout << u << " ";
	st[u] = true;
	
	for(int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if(!st[v])
		{
			dfs(v);
		}
	}
}

int main()
{
	 //����
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	} 
	
	//������ȱ���
	dfs(1); 
	
	return 0;
 } 
