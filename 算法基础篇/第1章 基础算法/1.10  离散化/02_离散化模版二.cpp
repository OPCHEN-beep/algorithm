//��ɢ����ʽ��������STL
//�����Ǻͷ�ʽһһ���ģ�ֻ����������STL��ȥ���Լ����Ҹ�����
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];	//ԭʼ����

int tmp[N]; //�������������
int cnt;
unordered_map<int ,int> id;//��¼��ɢ��֮���ֵ

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		tmp[i] = x;	//���ݷŽ���ɢ��������	
	}	
	
	//��ɢ�������� + �Ž���ϣ����
	sort(tmp + 1, tmp + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		if(id.count(tmp[i])) continue;	//����Ѿ������������Ͳ�������
		cnt++;	//�����ӳ��֮���ֵ
		id[tmp[i]] = cnt;	//�Ž���ϣ���� 
	 } 
	 
	//�ҵ���ɢ��֮���ֵ
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		cout << x << "��ɢ��֮���ǣ�" << id[a[i]] << endl;	//���ֲ�����ɢ��֮���ֵ 
	 } 
	 
	return 0; 
 } 
