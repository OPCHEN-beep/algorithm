//# P2142 �߾��ȼ���
//
//## ��Ŀ����
//
//�߾��ȼ�����
//
//## �����ʽ
//
//�������� $a,b$���ڶ������ܱȵ�һ���󣩡�
//
//## �����ʽ
//
//������Ǹ���Ҫ������ţ���
//
//## ����������� #1
//
//### ���� #1
//
//```
//2
//1
//```
//
//### ��� #1
//
//```
//1
//```
//
//## ˵��/��ʾ
//
//- $20\%$ ���� $a,b$ �� long long ��Χ�ڣ�
//- $100\%$ ���� $0<a,b\le 10^{10086}$��

#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1e6 + 10;

int a[N], b[N], c[N];
int la, lb, lc;

//�ȴ�С
bool cmp(string& x, string& y)
{
    //�ȱȽϳ���
    if(x.size() != y.size()) return x.size() < y.size();

    //�ٰ��� ���ֵ��� �ķ�ʽ�Ƚ�
    return x < y;
}

//�߾��ȼ�����ģ�� - c = a - b
void sub(int c[], int a[], int b[])
{
    for(int i = 0; i < lc; i++)
    {
        c[i] += a[i] - b[i];//��Ӧλ�����Ȼ�����λ
        if(c[i] < 0)
        {
            c[i + 1] -= 1;//��λ
            c[i] += 10;
        }
    }
    //����ǰ����
    while(lc > 1 && c[lc - 1] == 0) lc--;
}

int main()
{
	string x, y;
	cin >> x >> y;

    //�ȴ�С
    if(cmp(x, y))
    {
        swap(x, y);
        cout << '-';
    }
	
	//1.���ÿһλ���������������
	la = x.size(); lb = y.size(); lc = max(la, lb);
	for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
	for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
	
	//2.ģ������Ĺ���
	sub(c, a, b);	//c = a + b
	
	
	//������
	for(int i = lc - 1; i >= 0; i--) cout << c[i];
	
	return 0;
 } 
