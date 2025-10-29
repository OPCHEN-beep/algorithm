//# B2136 �����������ĸ���
//
//## ��Ŀ����
//
//�� $11$ �� $n$ ֮�䣨���� $n$���������������ǻ������������ж��ٸ���
//
//## �����ʽ
//
//һ������ $11$ С�� $10000$ ������ $n$��
//
//## �����ʽ
//
//$11$ �� $n$ ֮�������������������
//
//## ����������� #1
//
//### ���� #1
//
//```
//23
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
//������ָ���ҶԳƵ������磺$11$��$12121$��

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
    int j = 0;
    if(n < 2)
        return false;
    for(j = 2; j <= sqrt(n); j++)
    {
        if(n % j == 0)
            return false;
    }
    return true;
}

bool IsHuiwen(int n)
{
    int tmp = n;
    int ret = 0;
    while(tmp)
    {
        ret  =ret * 10 + tmp % 10;
        tmp /= 10;
    }
    if(ret == n)
        return true;
    else
        return false;
}

int main()
{
    int n = 0;
    int cnt = 0;
    cin >> n;
    for(int i = 11; i <= n; i++)
    {
        if(IsPrime(i) && IsHuiwen(i))
        {
            cnt++;
        }
 
    }
    cout << cnt << endl;
    return 0;
}
