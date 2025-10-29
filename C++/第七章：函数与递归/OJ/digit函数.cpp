//# B2145 digit ����
//
//## ��Ŀ����
//
//�ڳ����ж���һ���� $digit(n,k)$�����ܷ�������� $n$ ���ұ����� $k$ �����֡�
//
//## �����ʽ
//
//������ $n$ �� $k$��
//
//## �����ʽ
//
//һ�����֡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//31859 3
//```
//
//### ��� #1
//
//```
//8
//```
//
//## ˵��/��ʾ
//
//$n \le 10^9$��
//
//$k \le 10$��

#include <iostream>
#include <cstdio>
using namespace std;

int digit(int n, int k)
{
    if(k == 1)
        return n % 10;
    else
        return digit(n / 10, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ret = digit(n, k);
    cout << ret << endl;
    
    return 0;
}
