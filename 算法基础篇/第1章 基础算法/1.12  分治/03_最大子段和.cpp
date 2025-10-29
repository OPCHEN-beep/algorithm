//# P1115 ����Ӷκ�
//
//## ��Ŀ����
//
//����һ������Ϊ $n$ ������ $a$��ѡ�����������ҷǿյ�һ��ʹ����κ����
//
//## �����ʽ
//
//��һ����һ����������ʾ���еĳ��� $n$��
//
//�ڶ����� $n$ ���������� $i$ ��������ʾ���еĵ� $i$ ������ $a_i$��
//
//## �����ʽ
//
//���һ��һ��������ʾ�𰸡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//7
//2 -4 3 -1 2 -4 3
//```
//
//### ��� #1
//
//```
//4
//```
//
//## ˵��/��ʾ
//
//#### ���� 1 ����
//
//ѡȡ $[3, 5]$ �Ӷ� $\{3, -1, 2\}$�����Ϊ $4$��
//
//#### ���ݹ�ģ��Լ��
//
//- ���� $40\%$ �����ݣ���֤ $n \leq 2 \times 10^3$��
//- ���� $100\%$ �����ݣ���֤ $1 \leq n \leq 2 \times 10^5$��$-10^4 \leq a_i \leq 10^4$��

#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];

int dfs(int l, int r)
{
    if(l == r) return a[l];

    int mid = (l + r) >> 1;
    //����һ���������ߵ����ֵ
    int ret = max(dfs(l, mid), dfs(mid + 1, r));

    int suml = a[mid], sumr = a[mid + 1];
    int maxl = suml, maxr = sumr;

    //�����a[mid]Ϊ��ʼ��������������ֵ
    for(int i = mid - 1; i >= l; i--)
    {
        suml += a[i];
        maxl = max(maxl, suml);
    }

    //�����a[mid + 1]��ʼ��������������ֵ
    for(int i = mid + 2; i <= r; i++)
    {
        sumr += a[i];
        maxr = max(maxr, sumr);
    }

    //����������������ֵ
    return max(maxr + maxl, ret);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << dfs(1, n) << endl;

    return 0;
}
