//# B2144 ��������Ackermann������
//
//## ��Ŀ����
//
//��������Ackermann������ $A(m,n)$ �У�$m, n$ �������ǷǸ�������$m \le 3$��$n \le 10$��������ֵ����Ϊ��
//
//$\mathit{A}(m,n)=n+1$����$m=0$ ʱ����
//
//$\mathit{A}(m,n)=\mathit{A}(m-1,1)$����$m>0$��$n=0$ ʱ����
//
//$\mathit{A}(m,n)=\mathit{A}(m-1,\mathit{A}(m,n-1))$����$m,n>0$ ʱ����
//
//## �����ʽ
//
//$m$ �� $n$��
//
//## �����ʽ
//
//����ֵ��
//
//## ����������� #1
//
//### ���� #1
//
//```
//2 3
//```
//
//### ��� #1
//
//```
//9
//```

#include <iostream>
#include <cstdio>
using namespace std;

int akm(int m, int n)
{
    if(m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return akm(m - 1, 1);
    else if(m > 0 && n > 0)
        return akm(m - 1, akm(m, n - 1));
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << akm(m, n) << endl;

    return 0;
}
