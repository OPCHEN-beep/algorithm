//# B2085 �� n С������
//
//## ��Ŀ����
//
//����һ�������� $n$������������Χ�е� $n$ С��������
//
//## �����ʽ
//
//һ�������� $30000$ �������� $n$��
//
//## �����ʽ
//
//�� $n$ С��������
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
//29
//```

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i =2;
    int cnt = 0;
    while(1)
    {
        int flag =1 ;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cnt++;
        }
        if(cnt == n)
            break;
        i++;
    }
    cout << i << endl;

    return 0;
}
