//# B2139 �����ڵ�������
//
//## ��Ŀ����
//
//�ҳ������� $M$ �� $N$ ֮�䣨$N$ ��С�� $M$����������������
//
//�������Ķ��壺���һ�������� $P$ Ϊ���������䷴��ҲΪ��������ô $P$ ��Ϊ��������
//
//���磬$11$��$13$ ��Ϊ����������Ϊ $11$ �ķ�����Ϊ $11$��$13$ �ķ���Ϊ $31$ ҲΪ������
//
//## �����ʽ
//
//���������� $M$ �� $N$���ո�����
//
//## �����ʽ
//
//����С������� $M$ �� $N$ ֮�䣨���� $M$ �� $N$���������������ż�������֮��û��������������� `No`��
//
//## ����������� #1
//
//### ���� #1
//
//```
//10 35
//```
//
//### ��� #1
//
//```
//11,13,17,31
//```
//
//## ˵��/��ʾ
//
//$1 \le M \le N \le 100000$


#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool IsPrime(int n)
{
    if(n <= 1)
        return false;
    for(int j = 2; j <=sqrt(n); j++)
    {
        if(n % j == 0)
            return false;
    }
    return true;
}

int ReverseInt(int k)
{
    
    int ret = 0;
    while(k)
    {
        ret  = ret * 10 + k % 10;
        k /= 10;
    }
    return ret;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int flag = 0;
    int  i = 0;
    for( i = m; i <= n; i++)
    {
        int i2 = ReverseInt(i);
        if(IsPrime(i) && IsPrime(i2))
        {
            if(flag)
                cout << ",";
            cout << i;
            flag++;
        }
    }
    if(flag == 0)
        cout << "No" << endl;

    return 0;
}
