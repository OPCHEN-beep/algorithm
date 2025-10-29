//# P1226 ��ģ�塿������
//
//## ��Ŀ����
//
//������������ $a,b,p$���� $a^b \bmod p$��
//
//## �����ʽ
//
//����ֻ��һ�������������ֱ���� $a,b,p$��
//
//## �����ʽ
//
//���һ��һ���ַ��� `a^b mod p=s`������ $a,b,p$ �ֱ�Ϊ��Ŀ������ֵ�� $s$ Ϊ��������
//
//## ����������� #1
//
//### ���� #1
//
//```
//2 10 9
//```
//
//### ��� #1
//
//```
//2^10 mod 9=7
//```
//
//## ˵��/��ʾ
//
//**��������**
//
//$2^{10} = 1024$��$1024 \bmod 9 = 7$��
//
//**���ݹ�ģ��Լ��**
//
//���� $100\%$ �����ݣ���֤ $0\le a,b < 2^{31}$��$a+b>0$��$2 \leq p \lt 2^{31}$��

#include <iostream>
using namespace std;

typedef long long LL;

//a^b % p��ֵ
LL quickpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1)ret = ret * a % p;
        a = a * a % p;
        b >>= 1;  //��ȡb�Ķ�����λ
    }
    return ret;
}

int main()
{
    LL a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quickpow(a, b, p));

    return 0;                                            
}
