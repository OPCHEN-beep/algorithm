#include <iostream>
using namespace std;

const int N = 1e5 + 10;

//����ջ
int stk[N], n;

//��ջ - �����Ͼ���˳��������β��
void push(int x)
{
	stk[++n] = x;
 } 

//��ջ - ˳����βɾ����
void pop()
{
	n--;
 } 
 
 //��ѯջ��Ԫ��
 int top()
{
 	return stk[n];
} 

//�ж��Ƿ�Ϊ��
bool empty()
{
	return n == 0;
 } 
 
 //��ѯ��ЧԪ�صĸ���
 int size() 
{
	return n;
}

int main()
{
	for(int i = 1; i <= 10; i++)
	{
		push(i);
	}
	
	//��ջ��Ϊ�յ�ʱ�� 
	while(!empty())
	{
		cout << top() << endl;
		pop();
	}
	
	return 0;
 } 
