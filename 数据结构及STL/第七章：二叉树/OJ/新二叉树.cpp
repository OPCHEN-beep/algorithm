//# P1305 �¶�����
//
//## ��Ŀ����
//
//����һ���������������ǰ�������
//
//## �����ʽ
//
//��һ��Ϊ�������Ľڵ��� $n$��($1 \leq n \leq 26$)
//
//���� $n$ �У�ÿһ����ĸΪ�ڵ㣬��������ĸ�ֱ�Ϊ�����Ҷ��ӡ��ر�أ����ݱ�֤��һ�ж���Ľڵ��Ϊ���ڵ㡣
//
//�սڵ��� `*` ��ʾ
//
//## �����ʽ
//
//��������ǰ�������
//
//## ����������� #1
//
//### ���� #1
//
//```
//6
//abc
//bdi
//cj*
//d**
//i**
//j**
//```
//
//### ��� #1
//
//```
//abdicj
//```

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
char root;
char l[N], r[N];

void dfs(char root)
{
    if(root == '*')
        return;
    cout << root;
    dfs(l[root]);
    dfs(r[root]);
}

int main()
{
    cin >> n;
    cin >> root;
    cin >> l[root] >> r[root];
    
    for(int i = 2; i <= n; i++)
    {
        char t;
        cin >> t;
        cin >> l[t] >> r[t];
    }

    dfs(root);

    return 0;
}
