//# B2125 ��߷�����ѧ������
//
//## ��Ŀ����
//
//����ѧ����������Ȼ��������ÿλѧ���ķ�����������������߷�����ѧ����������
//
//## �����ʽ
//
//��һ������һ�������� $N$��$N \le 100$������ʾѧ��������
//
//�������� $N$ �У�ÿ�а���һ��������һ���ַ������ÿո�ֿ����������������
//
//������һ���Ǹ���������С�ڵ��� $100$��
//
//����Ϊһ���������ַ������м�û�пո񣬳��Ȳ����� $20$��
//
//���ݱ�֤����ͬѧ����������ͬ��������߷�ֻ��һλͬѧ��
//
//## �����ʽ
//
//�����߷���ͬѧ��������
//
//## ����������� #1
//
//### ���� #1
//
//```
//5
//87 lilei
//99 hanmeimei
//97 lily
//96 lucy
//77 jim
//```
//
//### ��� #1
//
//```
//hanmeimei
//```
//
//## ˵��/��ʾ
//
//hanmeimei �ķ������ $99$ �֡�

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 110;

struct Stu
{
    int score;
    string name;
}arr[N];

//����
bool cmp(struct Stu s1, struct Stu s2)
{
    return s1.score > s2.score;
}


int main()
{
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].score >> arr[i].name;
    }
    sort(arr, arr + n, cmp);
    cout << arr[0].name << endl;

    return 0;
}
