//# P2085 ��С����ֵ
//
//## ��Ŀ����
//
//�� $n$ ���������ֱ�Ϊ $F_1,F_2,\dots,F_n$������ $F_i(x)=A_ix^2+B_ix+C_i(x\in\mathbb N*)$��������Щ $A_i$��$B_i$ �� $C_i$����������к��������к���ֵ����С�� $m$ ���������ظ���Ҫ����������
//
//## �����ʽ
//
//��һ���������������� $n$ �� $m$��  
//
//���� $n$ ��ÿ�����������������е� $i$ �е��������ֱ�Ϊ $A_i$��$B_i$ �� $C_i$��
//
//## �����ʽ
//
//������� $n$ ���������п������ɵĺ���ֵ������ǰ $m$ ��Ԫ�ء��� $m$ ����Ӧ�������һ�У��ÿո������
//
//## ����������� #1
//
//### ���� #1
//
//```
//3 10
//4 5 3
//3 4 5
//1 7 1
//```
//
//### ��� #1
//
//```
//9 12 12 19 25 29 31 44 45 54
//```
//
//## ˵��/��ʾ
//
//#### ���ݹ�ģ��Լ��
//
//����ȫ���Ĳ��Ե㣬��֤ $1 \leq n,m\le10000$��$1 \leq A_i\le10$,
//$0 \leq B_i\le100$,
//$0 \leq C_i\le10^4$��

#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;
typedef long long LL;
int n, m;
int a[N], b[N], c[N];


struct Node
{
    LL f;
    int num;
    int x;

    bool operator<(const Node& x) const
    {
        //С���ѣ����Ԫ����׹
        return f > x.f;
    }
};

priority_queue<Node> heap;

LL calc(LL i, LL x)
{
    return a[i] * x * x + b[i] * x + c[i];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    //1.��x = 1��ֵ�������
    for(int i = 1; i <= n; i++)
    {
        heap.push({calc(i, 1), i, 1});
    }

    //2.�����ó�m��ֵ
    while(m--)
    {
        auto t = heap.top();
        heap.pop();
        int f = t.f, num = t.num, x = t.x;

        cout << f << " ";

        //����һ������ֵ�������
        heap.push({calc(num, x + 1), num, x + 1});
    }

    return 0;
}
