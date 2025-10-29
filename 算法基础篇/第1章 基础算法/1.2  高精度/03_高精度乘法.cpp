//# P1303 A*B Problem
//
//## ��Ŀ����
//
//�߾��ȳ˷�ģ���⡣
//
//## ��Ŀ����
//
//���������Ǹ������������ǵĳ˻���
//
//## �����ʽ
//
//���빲���У�ÿ��һ���Ǹ�������
//
//## �����ʽ
//
//���һ���Ǹ�������ʾ�˻���
//
//## ����������� #1
//
//### ���� #1
//
//```
//1 
//2
//```
//
//### ��� #1
//
//```
//2
//```
//
//## ˵��/��ʾ
//
//ÿ���Ǹ����������� $10^{2000}$��

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], b[N], c[N];
int la, lb, lc;

//�߾��ȳ˷���ģ�� - c = a * b
void mul(int c[], int a[], int b[])
{
    //�޽�λ��ˣ� Ȼ�����
    for(int i = 0; i < la; i++)
    {
        for(int j = 0; j < lb; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }

    //�����λ
    for(int i = 0; i < lc; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    //����ǰ����
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
    string x, y;
	cin >> x >> y;
	
	//1.���ÿһλ���������������
	la = x.size(); lb = y.size(); lc = la + lb;
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	
	//2.ģ��˷��Ĺ���
	mul(c, a, b);	//c = a + b
	
	//������
	for(int i = lc - 1; i >= 0; i--) cout << c[i];

    return 0;
}
