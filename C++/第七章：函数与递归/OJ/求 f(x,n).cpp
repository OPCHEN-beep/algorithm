//# B2147 �� f(x,n)
//
//## ��Ŀ����
//
//��֪ $f(x,n)=\sqrt{n+\sqrt{(n-1)+\sqrt{(n-2)+\sqrt{...+2+\sqrt{1+x}}}}}$��
//
//���� $f$ ��ֵ��
//
//## �����ʽ
//
//���� $x$ �� $n$��
//
//## �����ʽ
//
//����ֵ��������λС����
//
//## ����������� #1
//
//### ���� #1
//
//```
//4.2 10
//```
//
//### ��� #1
//
//```
//3.68
//```
//
//## ˵��/��ʾ
//
//#### ���ݷ�Χ
//
//���� $100\%$ �����ݣ�$1 \le x,n \le 10$��

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double func(int x, int n)
{
    if(n == 1)
        return sqrt(1 + x);
    else
        return sqrt(n + func(x, n - 1));
}

int main()
{
    int x, n;
    cin >> x >> n;

    double ret = func(x, n);
    printf("%.2lf\n", ret);

    return 0;
}
