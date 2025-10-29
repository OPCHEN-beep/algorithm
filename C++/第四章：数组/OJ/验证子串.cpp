//# B2118 ��֤�Ӵ�
//
//## ��Ŀ����
//
//���������ַ�������֤����һ�����Ƿ�Ϊ��һ�������Ӵ���
//
//## �����ʽ
//
//���У�ÿ��һ���ַ�����
//
//## �����ʽ
//
//����һ���� $s_1$ �ǵڶ����� $s_2$ ���Ӵ��������`(s1) is substring of (s2)`��
//
//�������ڶ����� $s_2$ �ǵ�һ���� $s_1$ ���Ӵ������`(s2) is substring of (s1)`��
//
//������� `No substring`��
//
//## ����������� #1
//
//### ���� #1
//
//```
//abc
//dddncabca
//```
//
//### ��� #1
//
//```
//abc is substring of dddncabca
//```
//
//## ����������� #2
//
//### ���� #2
//
//```
//aaa
//bbb
//```
//
//### ��� #2
//
//```
//No substring
//```
//
//## ˵��/��ʾ
//
//���� $100 \%$ �����ݣ��ַ��������� $30$ ���ڡ�

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20;
char s1[N];
char s2[N];

int main()
{
    cin >> s1;
    cin >> s2;

    if(strstr(s2, s1))
    {
        cout << s1 << " is substring of " << s2 << endl;
    }
    else if(strstr(s1, s2))
    {
        cout << s2 << " is substring of " << s1 << endl;
    }
    else{
        cout << "No substring" << endl;
    }

    return 0;
}
