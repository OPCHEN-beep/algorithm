//# P1923 �����9.��4����� k С����
//
//## ��Ŀ����
//
//���� $n$��$1 \le n < 5000000$ �� $n$ Ϊ������������ $a_i$��$1 \le a_i < {10}^9$���������Щ���ֵĵ� $k$ С��������С�����ǵ� $0$ С��
//
//�뾡����Ҫʹ�� `nth_element` ��д���⣬��Ϊ������ص�������ϰ�����㷨��
//
//## �����ʽ
//
//��һ���������������ֱ��ʾ $n$ �� $k$��
//
//�ڶ����� $n$ ���������� $i$ ������ʾ $a_i$��
//
//## �����ʽ
//
//һ����������ʾ�� $k$ С������
//
//## ����������� #1
//
//### ���� #1
//
//```
//5 1
//4 3 2 1 5
//```
//
//### ��� #1
//
//```
//2
//```

#include <iostream>
#include <ctime>

using namespace std;

const int N = 5e6 + 10;

int n, k;
int a[N];

//[l, r]֮���������һ����
int get_random(int l, int r)
{
    return a[rand() % (r - l + 1) + l];
}

int quick_select(int l, int r, int k)
{
    if(l == r) return a[l];

    //���ѡ���׼Ԫ��
    int p = get_random(l, r);

    //��pΪ��׼����������
    int x = l - 1, y = r + 1, i = l;
    while(i < y)
    {
        if(a[i] == p) i++;
        else if(a[i] < p) swap(a[++x], a[i++]);
        else swap(a[--y], a[i]);

        //[l, x][x + 1, y - 1][y, r]
        int c1 = x - l + 1, c2 = y - 1 - x, c3 = r - y + 1;
        if(k <= c1) return quick_select(l, x, k);
        else if(k <= c1 + c2) return p;
        else return quick_select(y, r, k - c1 - c2);
    }
}

int main()
{
    srand(time(0));

    scanf("%d%d", &n, &k);
    k++;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", quick_select(1, n, k));

    return 0;
}
