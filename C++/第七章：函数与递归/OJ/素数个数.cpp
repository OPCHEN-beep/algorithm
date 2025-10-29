//# B2128 ��������
//
//## ��Ŀ����
//
//����� $2$ �� $n(n$ Ϊ���ڵ��� $2$ �������������ж��ٸ�������
//
//## �����ʽ
//
//���� $n(2 \le n \le 50000)$��
//
//## �����ʽ
//
//����������
//
//## ����������� #1
//
//### ���� #1
//
//```
//10
//```
//
//### ��� #1
//
//```
//4
//```

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

int main()
{
    int n = 0;
    int cnt = 0;
    cin >> n;
    int i = 0;
    for(i = 2; i <= n; i++)
    {
        if(IsPrime(i))
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
