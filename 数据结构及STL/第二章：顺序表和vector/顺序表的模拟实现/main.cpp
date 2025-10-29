#include <iostream>

using namespace std;

const int N = 1e6 + 10;	//����ʵ���������


class SqList
{
	int a[N];	//���㹻���������ģ��ʵ��˳���
	int n;		//���˳��������ж��ٸ�Ԫ��
	
	public:
		//���캯��
		SqList()
		{
			n = 0;
		} 
		
		//β��
		void push_back(int x)
		{
			a[++n] = x;
		} 
		
		//��ӡ˳���
		void print() 
		{
			for(int i = 1; i <= n; i++)
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}


		//ͷ��
		void push_front(int x)
		{
			//1.�Ȱ�[1, n]��Ԫ��ͳһ����ƶ�һλ
			for(int i = n; i >= 1; i--)
			{
				a[i + 1] = a[i];
			}
			//2.��x���ڱ�ͷ
			a[1] = x;
			n++; 
		} 


		//����λ�ò���
		void insert(int p, int x)
		{
			for(int i = n; i >= p; i--)
			{
				a[i + 1] = a[i];	
			}
			a[p] = x;
			n++;
		} 


		//βɾ
		void pop_back()
		{
			n--;	
		} 


		//ͷɾ
		void pop_front()
		{
			for(int i = 2; i <= n; i++)
			{
				a[i - 1] = a[i];
			}
			n--;
		} 


		//����λ��ɾ������
		void erase(int p)
		{
			for(int i = p + 1; i <= n; i++)
			{
				a[i - 1] = a[i];	
			}
			n--;
		} 


		//��ֵ����
		int find(int x)
		{
			for(int i  = 1; i <= n; i++)
			{
				if(i == x)
					return i;	
			}	
			return 0;
		} 


		//��λ����
		int at(int p)
		{
			return a[p];
		} 


		//��λ�޸�
		int change(int p, int x)
		{
			a[p] = x;
 		} 


		//���˳���
		void clear()
		{
			n = 0;
 		} 	
};



//int main()
//{
	//����β��
//	push_back(1);
//	print();
//	push_back(2);
//	print(); 
//	push_back(3);
//	print();
//	push_back(4);
//	print();
//	push_back(5);
//	print();
//	push_back(6);
//	print();
//	push_back(7);
//	print();
//	push_back(8);
//	print();
//	push_back(9);
//	print();
//	push_back(10);
//	print();

//	//����ͷ�� 
//	push_front(1);
//	print();
//	push_front(2);
//	print(); 
//	push_front(3);
//	print();
//	push_front(4);
//	print();
//	
//	insert(3, 10);
//	print();
//	
//	//����βɾ
//	cout << "βɾ��" << endl;
//	pop_back();
//	print(); 
//	
//	//����ͷɾ 
//	cout << "ͷɾ��" << endl;
//	pop_front();
//	print();
//	
//	//����ɾ������λ������
//	cout << "ɾ������λ�����ݣ�" << endl;
//	erase(3);
//	print();
//	erase(3);
//	print();
//
//	for(int i = 1; i <= 10; i++)
//	{
//		cout << "����" << i << ":";
//		cout << find(i) << endl;
//		
//	}
//
//
//	
//	return 0;
// } 


int main()
{
	
	SqList s1, s2;
	for(int i = 1; i <= 5; i++)
	{
		s1.push_back(i);
		s2.push_back(i * 2);
	} 
	
	s1.print();
	s2.print();
	
	return 0;
}
