//# B2129 ����� max(x,y,z)
//
//## ��Ŀ����
//
//��֪��
//
//$m=\dfrac{\max(a,b,c)}{\max(a+b,b,c) \times \max(a,b,b+c)}$
//
//������������ $a$��$b$��$c$���� $m$��
//
//����������������� $\max(x,y,z)$ �ֱ���ɺ����͹���������
//
//## �����ʽ
//
//����ֻ��һ���������������ֱ�Ϊ $a, b, c$��
//
//## �����ʽ
//
//���һ��һ��С����Ϊ�𰸣�������λС����
//
//## ����������� #1
//
//### ���� #1
//
//```
//1 2 3
//```
//
//### ��� #1
//
//```
//0.200
//```
//
//## ˵��/��ʾ
//
//### ���ݹ�ģ��Լ��
//
//����ȫ���Ĳ��Ե㣬��֤ $|a|,|b|,|c| \leq 50$�����仰˵��$a,b,c$ ���� $-50$ �� $50$ ֮�䡣
//
//�������ݱ�֤����ʽ�ķ�ĸ��Ϊ $0$��

#include <iostream>
using namespace std;


int max(int a, int b, int c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= a && b >= c)
        return b;
    else if(c >= a && c >= b)
        return c;
}

int main()
{
    ios::sync_with_stdio(false); //ȡ����C��?��?�����������ͬ��
    cin.tie(0); //ȡ����cin��cout�İ�
    
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    double m = 0;
    m = max(a, b, c) * 1.0 / (max(a + b, b, c) * max(a, b, b + c));

    printf("%.3lf\n", m);

    return 0;
}
