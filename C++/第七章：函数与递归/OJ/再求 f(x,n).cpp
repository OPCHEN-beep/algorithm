//# B2148 ���� f(x,n)
//
//## ��Ŀ����
//
//��֪
//
//$f(x,n)=\dfrac{x}{n+\dfrac{x}{(n-1)+\dfrac{x}{(n-2)+\dfrac{\vdots}{\cdots+\dfrac{x}{1+x}}}}}$��
//
//�õݹ麯����⡣
//
//## �����ʽ
//
//��һ������ $x$ ��ֵ���ڶ������� $n$ ��ֵ����$x$ Ϊ**ʵ��**��$n$ Ϊ������
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
//1
//2
//```
//
//### ��� #1
//
//```
//0.40
//```

#include <iostream>
#include <cstdio>

using namespace std;

double func(double x, int n)
{
    if(n == 1)
        return x * 1.0 / (1 + x);
    else
        return x * 1.0 / (n + func(x, n - 1));
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double ret = func(x, n);
    printf("%.2lf\n", ret);

    return 0;
}
