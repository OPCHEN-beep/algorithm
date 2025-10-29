#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

struct node
{
	int a, b;
	string s;
};

void print(vector<int>& a)	//�����ã�����Ҫ���� 
{
	//����size���� 
//	for(int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;

	//���õ���������
//	for(auto it = a.begin(); it != a.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;

	//ʹ�÷�Χfor	--- ���ڵ������Ϳ���ʹ�� 
	for(auto x: a)
	{
		cout << x << " ";	
	} 
	cout << endl;
}

int main()
{
	//1.����vector
	vector<int> a1;			//����һ������Ϊa1�ĿյĿɱ䳤���飬��������ݶ���int����
	vector<int> a2(N);  	//����һ������Ϊa2�Ĵ�СΪ10�Ŀɱ䳤���飬��������ݶ���int����
	vector<int> a3(N, 2);	//����һ����СΪ10�Ŀɱ䳤���飬�����ֵ����ʼ��Ϊ2
	vector<int> a4 = {1, 2, 3, 4, 5};//��ʼ���б�Ĵ�����ʽ
	//<>���Դ��������������� ��������STL����
	vector<string> a5;//���ַ���
	vector<node> a6;  //��ṹ��
	vector<vector<int>> a7;//����һ����ά�Ŀɱ䳤����
	vector<int> a8[N];	//����һ����СΪN��vector���飨Ԫ�ض���vector��Ϊ��ά�� 
	
	
	//2.size��empty
//	print(a2);
//	print(a3);
//	print(a4);
//	if(a1.empty())
//		cout << "��" << endl;
		
	//3.begin��end
//	print(a2);
//	print(a3);
//	print(a4);
	
	//4.push_back��pop_back
//	for(int i = 0; i < 5; i++)
//	{
//		a1.push_back(i);
//		print(a1);
//	}
//	while(!a1.empty())
//	{
//		print(a1);
//		a1.pop_back();
//	}

	//5.front\back
//	cout << a4.front() << " " << a4.back() << endl;	
	
	//6.resize
	vector<int> aa(5, 1);
	print(aa);
	
	//�����10
	aa.resize(10);
	print(aa);
	//��С��3
	aa.resize(3);
	print(aa); 
	
	//7.clear
	cout << aa.size() << endl;
	aa.clear();
	cout << aa.size() << endl;	
	
	return 0;
}
