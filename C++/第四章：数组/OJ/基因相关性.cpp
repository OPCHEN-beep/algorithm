//# B2111 ���������
//
//## ��Ŀ����
//
//Ϊ�˻�֪���������ڹ��ܺͽṹ�ϵ������ԣ�������Ҫ��������ͬ���е� DNA ���бȶԣ����жϸñȶԵ� DNA �Ƿ��������ԡ�
//
//�ֱȶ�����������ͬ�� DNA ���С����ȶ������� DNA ������ͬλ�õļ��Ϊһ������ԣ����һ��������е����������ͬ�Ļ������Ϊ��ͬ����ԡ����ż�����ͬ�����ռ�ܼ���������ı���������ñ������ڵ��ڸ�����ֵʱ���ж������� DNA ��������صģ�������ء�
//
//## �����ʽ
//
//�����У���һ���������ж������� DNA �����Ƿ���ص���ֵ����� $2$ �������� DNA ���У����Ȳ����� $500$����
//
//## �����ʽ
//
//������ DNA ������أ������ `yes`���������`no`��
//
//## ����������� #1
//
//### ���� #1
//
//```
//0.85
//ATCGCCGTAAGTAACGGTTTTAAATAGGCC
//ATCGCCGGAAGTAACGGTCTTAAATAGGCC
//```
//
//### ��� #1
//
//```
//yes
//```

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 510;
char arr1[N];
char arr2[N];

int main()
{
    float flag = 0;
    cin >> flag;
    cin >> arr1;
    cin >> arr2;

    int len = strlen(arr1);
    int i = 0;
    int n = 0;

    while(arr1[i] != '\0')
    {
        if(arr1[i] == arr2[i])
            n++;
        i++;
    }

    if(n * 1.0 / len >= flag)
    {
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }

    return 0;
}
