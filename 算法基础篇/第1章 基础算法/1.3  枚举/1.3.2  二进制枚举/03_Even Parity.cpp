//# UVA11464 Even Parity
//
//## ��Ŀ����
//
//����һ�� $n \times n$ �� $01$ ����ÿ��Ԫ�ط� $0$ �� $1$������������ǰѾ����ٵ� $0$ ��� $1$��ʹ��ԭ�����Ϊż�����󣨾�����ÿ��Ԫ�ص��ϡ��¡����ҵ�Ԫ�أ�������ڵĻ���֮�;�Ϊż������
//
//## �����ʽ
//
//����ĵ�һ��Ϊ�������� $T$��$T \le 30$����ÿ�����ݣ���һ��Ϊ������ $n$��$1 \le n \le 15$������������ $n$ ��ÿ�а��� $n$ ���� $0$ �� $1$ ��������������������һ���ո������
//
//## �����ʽ
//
//����ÿ�����ݣ�������ı��Ԫ�ص���С����������޽⣬��� $-1$��
//
//## ����������� #1
//
//### ���� #1
//
//```
//3
//3
//0 0 0
//0 0 0
//0 0 0
//3
//0 0 0
//1 0 0
//0 0 0
//3
//1 1 1
//1 1 1
//0 0 0
//```
//
//### ��� #1
//
//```
//Case 1: 0
//Case 2: 3
//Case 3: -1
//```

#include <iostream>
#include <cstring>

using namespace std;

const int N = 20;

int n;
int a[N];//�ö����ƴ洢״̬
int t[N];//����

//�ж�x->y�Ƿ�Ϸ�
//����-1��ʾ���Ϸ�
//���������ʾ�Ϸ����ұ�ʾ0->1�Ĵ���
int calc(int x, int y)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) sum++;
        if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
    }

    return sum;
}

int solve()
{
    int ret = 0x3f3f3f3f;

    //ö�ٵ�һ�е�����״̬
    for(int st = 0; st < (1 << n); st++)
    {
        memcpy(t, a, sizeof a);

        int change = st;
        int cnt = 0;//ͳ��0->1�Ĵ���
        bool flag = 1;

        for(int i = 1; i <= n; i++)
        {
            //���ж�change�Ƿ�Ϸ�
            int c = calc(t[i], change);
            if(c == -1)
            {
                flag = 0;
                break;
            }

            cnt += c;//�ۼӴ���
            //��ǰ�е�����״̬
            t[i] = change;
            //������һ�е�����״̬
            change = t[i - 1] ^ (t[i] << 1) ^ (t[i] >> 1);
            change &= (1 << n) - 1;
        }

        if(flag) ret = min(ret, cnt);
    }

    if(ret == 0x3f3f3f3f) return -1;
    else return ret;
}

int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        memset(a, 0, sizeof a);

        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                if(x) a[i] |= 1 << j;
            }

        }

        printf("Case %d: %d\n", k, solve());
    }

    return 0;
}
