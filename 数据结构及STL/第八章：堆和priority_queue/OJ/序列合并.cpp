//# P1631 ���кϲ�
//
//## ��Ŀ����
//
//����������Ϊ $N$ ��**��������**���� $A,B$���� $A,B$ �и�ȡһ������ӿ��Եõ� $N^2$ ���ͣ����� $N^2$ ��������С�� $N$ ����
//
//## �����ʽ
//
//��һ��һ�������� $N$��
//
//�ڶ��� $N$ ������ $A_{1\dots N}$��
//
//������ $N$ ������ $B_{1\dots N}$��
//
//## �����ʽ
//
//һ�� $N$ ����������С�����ʾ�� $N$ ����С�ĺ͡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//3
//2 6 6
//1 4 8
//```
//
//### ��� #1
//
//```
//3 6 7
//```
//
//## ˵��/��ʾ
//
//���� $50\%$ �����ݣ�$N \le 10^3$��
//
//���� $100\%$ �����ݣ�$1 \le N \le 10^5$��$1 \le a_i,b_i \le 10^9$��

#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N];

struct Node
{
    int sum;//��ǰ�ĺ�
    int i, j;//a��b�ı��

    bool operator <(const Node& x) const
    {
        //С����
        return sum > x.sum;
    }
};

priority_queue<Node> heap;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    //1.��a[i] + b[i]�Ž�������
    for(int i = 1; i <= n; i++)
    {
        heap.push({a[i] + b[1], i, 1});
    }

    //2.�����ó�n����
    for(int k = 1; k <= n; k++)
    {
        Node t = heap.top();
        heap.pop();
        int sum = t.sum, i = t.i, j = t.j;

        cout << sum << " ";
        if(j + 1 <= n) heap.push({a[i] + b[j + 1], i, j + 1});
    }

    return 0;
}
