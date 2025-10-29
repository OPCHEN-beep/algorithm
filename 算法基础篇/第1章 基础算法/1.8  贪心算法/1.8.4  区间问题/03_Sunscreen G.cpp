//# P2887 [USACO07NOV] Sunscreen G
//
//## ��Ŀ����
//
//�� $C$ ͷ��ţ�����չ�ԡ���� $i$ ͷ��ţ��Ҫ $minSPF[i]$ �� $maxSPF[i]$ ��λǿ��֮������⡣
//
//ÿͷ��ţ���չ�ԡǰ����Ϳ��ɹ˪����ɹ˪�� $L$ �֣�Ϳ�ϵ� $i$ ��֮��������յ�������ǿ�Ⱦͻ��ȶ�Ϊ $SPF[i]$���� $i$ �ַ�ɹ˪�� $cover[i]$ ƿ��
//
//���������������ͷ��ţ�����չ�ԡ��
//
//## �����ʽ
//
//��һ���������� $C$ �� $L$��
//
//�������� $C$ �У�������ÿ������һͷţ�� $minSPF$ �� $maxSPF$ ֵ������ $i$ ������ $minSPF[i]$ �� $maxSPF[i]$��
//
//�ٽ������� $L$ �У�������ÿ������һ�ַ�ɹ˪�� $SPF$ �� $cover$ ֵ������ $i$ ������ $SPF[i]$ �� $cover[i]$��
//
//ÿ�е�����֮���ÿո������
//
//## �����ʽ
//
//���һ������������������������ţ�չ�ԡ����ţ��Ŀ��
//
//## ����������� #1
//
//### ���� #1
//
//```
//3 2
//3 10
//2 5
//1 5
//6 2
//4 1
//```
//
//### ��� #1
//
//```
//2
//```
//
//## ˵��/��ʾ
//
//�������ͣ�����һͷ��ţͿ��һ�ַ�ɹ˪���ڶ�ͷ��ţͿ�ڶ��ַ�ɹ˪��
//
//
//---
//
//
//���� $100\%$ �����ݣ�$1\le C,L\le 2500$��$1\le minSPF[i]\le maxSPF[i]\le 1000$��$1\le SPF[i]\le 1000$��$1\le cover[i]\le 2500$��

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;

int n, m;

struct node
{
    int x, y;
}a[N], b[N];

bool cmp1(node& x, node& y)
{
    return x.y < y.y;
}

bool cmp2(node& x, node& y)
{
    return x.x < y.x;
}

bool cmp3(node& x, node& y)
{
    return x.x > y.x;
}

//�������䰴���Ҷ˵��С��������
//���е㰴�մ�С��������
void solve1()
{
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + m, cmp2);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        for(int j = 1; j <= m; j++)
        {
            //ѡһ����С�ģ�����Ҫ��ĵ�
            int &sp = b[j].x, &cnt = b[j].y;
            if(!cnt || sp < l) continue;
            if(sp > r) break;
            cnt--;
            ret++;
            break;
        }
    }

    cout << ret << endl;
}

//�������䰴����˵�Ӵ�С����
//���е㰴�մӴ�С����
void solve2()
{
    sort(a + 1, a + 1 + n, cmp3);
    sort(b + 1, b + 1 + m, cmp3);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        for(int j = 1; j <= m; j++)
        {
            //ѡһ�����ġ�����Ҫ��ĵ�
            int &sp = b[j].x, &cnt = b[j].y;
            if(!cnt || sp > r) continue;
            if(sp < l) break;
            ret++;
            cnt--;
            break;
        }
    }

    cout << ret << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for(int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;

    //solve1();  //�����Ҷ˵�����
    solve2();  //������˵�����

    return 0;
}
