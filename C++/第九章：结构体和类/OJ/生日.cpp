//# P1104 ����
//
//## ��Ŀ����
//
//cjf �������ѧУ OI ��ÿ��ͬѧ�����գ�����������Ӵ�С��˳�����򡣵� cjf �������ҵ�ܶ࣬û��ʱ�䣬���������������
//
//## �����ʽ
//
//���빲�� $n + 1$ �У�
//
//�� $1$ ��Ϊ OI �������� $n$��
//
//�� $2$ ������ $n+1$ �зֱ���ÿ�˵����� $s$�������� $y$���� $m$���� $d$��
//
//## �����ʽ
//
//������� $n$ �У�
//
//�� $n$ �����մӴ�Сͬѧ�������������������ͬѧ������ͬ�����뿿���ͬѧ�������
//
//## ����������� #1
//
//### ���� #1
//
//```
//3
//Yangchu 1992 4 23
//Qiujingya 1993 10 13
//Luowen 1991 8 1
//```
//
//### ��� #1
//
//```
//Luowen
//Yangchu
//Qiujingya
//```
//
//## ˵��/��ʾ
//
//���ݱ�֤��$1<n<100$��$1\leq |s|<20$����֤������ʵ�ʴ��ڣ������ $\in [1960,2020]$��

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 110;

struct S
{
    string s;
    int y;
    int m;
    int d;
    int id;
}arr[N];

bool cmp(struct S s1, struct S s2)
{
    if(s1.y != s2.y)
        return s1.y < s2.y;
    else if(s1.m != s2.m)
        return s1.m < s2.m;
    else if(s1.d != s2.d)
        return s1.d < s2.d;
    else
        return s1.id > s2.id;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i].s >> arr[i].y >> arr[i].m >> arr[i].d;
        arr[i].id = i;
    }

    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i].s << endl;
    }
    
    return 0;
}
