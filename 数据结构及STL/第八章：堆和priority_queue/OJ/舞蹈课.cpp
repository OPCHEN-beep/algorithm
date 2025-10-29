//# P1878 �赸��
//
//## ��Ŀ����
//
//�� $n$ ���˲μ�һ���赸�Ρ�ÿ���˵��赸���������������������赸�εĿ�ʼ�����Ǵ�����վ��һ�š�����һ����������һ�����ڵ�����ʱ���赸���������С����һ�Ի���в���ʼ���衣�����ֹһ�ԣ���ô����ߵ���һ�Գ��С�һ�����Գ���֮�󣬶����еĿհװ�ԭ˳���ϣ�����������Ϊ `ABCD`����ô `BC` ����֮������Ϊ `AD`�����赸���������С���� $a_i$ �ľ���ֵ��С��
//
//������ģ�����Ϲ��̣�ȷ���������Լ�˳��
//
//## �����ʽ
//
//��һ��һ�������� $n$ ��ʾ�����е�������
//
//�ڶ��а��� $n$ ���ַ� `B` ���� `G`��`B` �����У�`G` ����Ů��
//
//������Ϊ $n$ ������ $a_i$��������Ϣ���մ����ҵ�˳�������
//
//## �����ʽ
//
//��һ��һ��������ʾ���е��ܶ��� $k$��
//
//������ $k$ �У�ÿ��������������������˳���������������������һ�����ı�ţ�������˳��������� $1$ �� $n$ ��ţ������������С��������������ϴ��������
//
//## ����������� #1
//
//### ���� #1
//
//```
//4
//BGBG
//4 2 4 3
//```
//
//### ��� #1
//
//```
//2
//3 4
//1 2
//```
//
//## ˵��/��ʾ
//
//���� $50\%$ �����ݣ�$1\leq n\leq 200$��
//
//���� $100\%$ �����ݣ�$1\leq n\leq 2\times 10^5$��$0\le a_i\le 10^7$��

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;

int n;
int s[N];//�����/Ů - 0/1

//˫�����������
int e[N];
int pre[N], ne[N];

struct node
{
    int d;//������
    int l, r;//���ұ��

    //С����
    bool operator<(const node& x) const
    {
        if(d != x.d) return d > x.d;
        else if(l != x.l) return l > x.l;
        else return r > x.r;
    }
};

priority_queue<node> heap;
bool st[N];//����Ѿ����ӵ���

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if(ch == 'B')
            s[i] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> e[i];
        //����˫������
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = ne[n] = 0;//0��ʾ����û��Ԫ��

    //1.�Ȱ����е����Բ�Ž�����
    for(int i = 2; i <= n; i++)
    {
        if(s[i] != s[i - 1])
        {
            heap.push({abs(e[i] - e[i - 1]), i - 1, i});
        }
    }

    //2.��ȡ���
    vector<node> ret;//�ݴ���

    while(heap.size())
    {
        node t = heap.top();
        heap.pop();
        int d = t.d, l = t.l, r = t.r;

        if(st[l] || st[r]) continue;

        ret.push_back(t);
        st[l] = st[r] = true;

        //�޸�ָ�룬��ԭ�µĶ���
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];

        //�ж��µ������Ƿ���Ϊһ��
        int left = pre[l], right = ne[r];
        if(left && right && s[left] != s[right])
        {
            heap.push({abs(e[left] - e[right]), left, right});
        }
    }

    cout << ret.size() << endl;
    for(auto& x : ret)
    {
        cout << x.l << " " << x.r << endl;
    }

    return 0;
}#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;

int n;
int s[N];//�����/Ů - 0/1

//˫�����������
int e[N];
int pre[N], ne[N];

struct node
{
    int d;//������
    int l, r;//���ұ��

    //С����
    bool operator<(const node& x) const
    {
        if(d != x.d) return d > x.d;
        else if(l != x.l) return l > x.l;
        else return r > x.r;
    }
};

priority_queue<node> heap;
bool st[N];//����Ѿ����ӵ���

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if(ch == 'B')
            s[i] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> e[i];
        //����˫������
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = ne[n] = 0;//0��ʾ����û��Ԫ��

    //1.�Ȱ����е����Բ�Ž�����
    for(int i = 2; i <= n; i++)
    {
        if(s[i] != s[i - 1])
        {
            heap.push({abs(e[i] - e[i - 1]), i - 1, i});
        }
    }

    //2.��ȡ���
    vector<node> ret;//�ݴ���

    while(heap.size())
    {
        node t = heap.top();
        heap.pop();
        int d = t.d, l = t.l, r = t.r;

        if(st[l] || st[r]) continue;

        ret.push_back(t);
        st[l] = st[r] = true;

        //�޸�ָ�룬��ԭ�µĶ���
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];

        //�ж��µ������Ƿ���Ϊһ��
        int left = pre[l], right = ne[r];
        if(left && right && s[left] != s[right])
        {
            heap.push({abs(e[left] - e[right]), left, right});
        }
    }

    cout << ret.size() << endl;
    for(auto& x : ret)
    {
        cout << x.l << " " << x.r << endl;
    }

    return 0;
}
