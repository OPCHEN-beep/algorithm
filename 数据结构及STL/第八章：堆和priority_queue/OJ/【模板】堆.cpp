//# P3378 ��ģ�塿��
//
//## ��Ŀ����
//
//����һ�����У���ʼΪ�գ���֧���������ֲ�����
//
//1. ����һ������ $x$���뽫 $x$ ���뵽�����С�
//2. �����������С������
//3. ɾ����������С����������ж������С��ֻɾ�� $1$ ������
//
//## �����ʽ
//
//��һ����һ����������ʾ�����Ĵ��� $n$��  
//������ $n$ �У�ÿ�б�ʾһ�β�����ÿ��������һ������ $op$ ��ʾ�������͡�
//- �� $op = 1$���������һ������ $x$����ʾҪ�� $x$ �������С�
//- �� $op = 2$�����ʾҪ����������е���С����
//- �� $op = 3$�����ʾɾ�������е���С��������ж������С��ֻɾ�� $1$ ����
//
//## �����ʽ
//
//����ÿ������ $2$�����һ��һ��������ʾ�𰸡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//5
//1 2
//1 5
//2
//3
//2
//```
//
//### ��� #1
//
//```
//2
//5
//```
//
//## ˵��/��ʾ
//
//**�����ݹ�ģ��Լ����**
//- ���� $30\%$ �����ݣ���֤ $n \leq 15$��
//- ���� $70\%$ �����ݣ���֤ $n \leq 10^4$��
//- ���� $100\%$ �����ݣ���֤ $1 \leq n \leq 10^6$��$1 \leq x \lt 2^{31}$��$op \in \{1, 2, 3\}$��

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int heap[N];

//���ϵ����㷨
void up(int child)
{
    int parent = child / 2;

    while(parent >= 1 && heap[child] < heap[parent])
    {
        swap(heap[child], heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

//���µ����㷨
void down(int parent)
{
    int child = parent * 2;

    while(child <= n)
    {
        //�ҳ����������е���Сֵ
        if(child + 1 <= n && heap[child + 1] < heap[child]) child++;

        if(heap[child] >= heap[parent]) return;

        swap(heap[child], heap[parent]);
        parent = child;
        child = parent * 2;
    }
}

//����
void push(int x)
{
    n++;
    heap[n] = x;

    up(n);
}

void pop()
{
    swap(heap[1], heap[n]);
    n--;

    down(1);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;

        if(op == 1)//����
        {
            int x; cin >> x;
            push(x);
        }
        else if(op == 2)//����Ѷ�
        {
            cout << heap[1] << endl;
        }
        else//ɾ���Ѷ�Ԫ��
        {
            pop();
        }
    }

    return 0;
}
