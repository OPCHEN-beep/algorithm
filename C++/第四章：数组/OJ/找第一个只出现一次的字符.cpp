//# B2110 �ҵ�һ��ֻ����һ�ε��ַ�
//
//## ��Ŀ����
//
//����һ��ֻ����Сд��ĸ���ַ����������ҵ���һ��������һ�ε��ַ������û�У���� `no`��
//
//## �����ʽ
//
//һ���ַ���������С�� $1100$��
//
//## �����ʽ
//
//�����һ��������һ�ε��ַ�����û������� `no`��
//
//## ����������� #1
//
//### ���� #1
//
//```
//abcabd
//```
//
//### ��� #1
//
//```
//c
//```
//
//## ����������� #2
//
//### ���� #2
//
//```
//aabbcc
//```
//
//### ��� #2
//
//```
//no
//```

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1110;
char str[N];
int nums[128];

int main()
{
    cin >> str;
    int i = 0;
    while(str[i])
    {
        nums[str[i]]++;
        i++;
    }
    i = 0;
    int flag = 0;
    while(str[i])
    {
        if(nums[str[i]] == 1)
        {
            cout << str[i] << endl;
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
    {
        cout << "no" << endl;
    }

    return 0;
}
