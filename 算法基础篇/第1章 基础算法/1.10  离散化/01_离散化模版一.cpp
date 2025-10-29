//��ɢ����ʽһ������ȥ�أ����ֲ�����ɢ�����ֵ
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];	//ԭʼ����

int pos;	//��¼��ɢ��������Ԫ�صĸ���
int disc[N];//��ɢ����Ҫ������

//���ֲ�����ɢ��֮���ֵ����ʵ��������֮����±�
int find(int x)
{
	int l = 1, r = pos;	//ע����ҵ�����
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(disc[mid] >= x) r = mid;
		else l = mid + 1;
	}	
	
	return l;
} 

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
		disc[++pos] = x;	//���ݷŽ���ɢ�������� 
	}
	
	//��ɢ��������ȥ��
	sort(disc + 1, disc + 1 + pos);
	pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);
	
	//�ҵ���ɢ��֮���ֵ
	for(int i = 1; i <= n; i++)
	{
		int x = a[i];
		cout << x << "��ɢ��֮���ǣ�" << find(x) << endl;	//���ֲ�����ɢ��֮���ֵ	
	} 
	
	return 0;
}
