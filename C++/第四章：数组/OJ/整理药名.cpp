//1139������ҩ��
//
//ʱ������: 1000 ms         �ڴ�����: 65536 KB
//�ύ��:67591    ͨ����: 35830
//����Ŀ������
//ҽ������дҩƷ����ʱ�򾭳���ע���Сд����ʽ�Ƚϻ��ҡ���Ҫ����дһ������ҽ����д���ҵ�ҩƷ�������ͳһ�淶�ĸ�ʽ����ҩƷ���ĵ�һ���ַ��������ĸҪ��д��������ĸСд���罫ASPIRIN��aspirin�����Aspirin��
//
//�����롿
//��һ��һ������n����ʾ��n��ҩƷ��Ҫ����n������100��
//
//������n�У�ÿ��һ�����ʣ����Ȳ�����20����ʾҽ�������ҩƷ����ҩƷ������ĸ�����ֺ�-��ɡ�
//
//�������
//n�У�ÿ��һ�����ʣ���Ӧ�����ҩƷ���Ĺ淶д����
//
//������������
//4
//AspiRin
//cisapride
//2-PENICILLIN
//Cefradine-6
//�����������
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
