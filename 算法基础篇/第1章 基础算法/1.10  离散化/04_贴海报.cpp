//# P3740 [HAOI2014] ������
//
//## ��Ŀ����
//
//Bytetown ����Ҫ�����г���ѡ�����е�ѡ����Գ������ԵضԾ�ѡ�г��ĺ�ѡ�˷������ۡ�Ϊ��ͳһ��������ίԱ��Ϊѡ��׼����һ������������ electoral ǽ��
//
//�����������£�
//
//1. electoral ǽ��һ������Ϊ $N$ ����λ�ĳ����Σ�ÿ����λ��Ϊһ�����ӣ�
//
//2. ���������ĺ����ĸ߶ȱ����� electoral ǽ�ĸ߶�һ�µģ�
//
//3. ÿ�ź����� `A B` ��ʾ�����ӵ� $A$ �����ӵ��� $B$ ����������������
//
//4. �����ĺ������Ը���ǰ�������ĺ����򲿷ֺ�����
//
//���������жϣ����������к������� electoral ǽ�ϻ����Կ��������ź�����
//
//## �����ʽ
//
//��һ�У����������� $N,M$���ֱ��ʾ electoral ǽ�ĳ��Ⱥͺ���������
//
//������ $M$ �У�ÿ������������ $A_i,B_i$����ʾÿ�ź���������λ�á�
//
//## �����ʽ
//
//����������к������� electoral ǽ�ϻ����Կ����ĺ�������
//
//## ����������� #1
//
//### ���� #1
//
//```
//100 5
//1 4
//2 6
//8 10
//3 4
//7 10
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
//![](https://cdn.luogu.com.cn/upload/pic/5209.png) 
//
//**Լ������**
//
//$10\le N \le 10000000,1\le M\le 1000,1\le A_i \le B_i \le 10000000$
//
//���е����ݶ���������������֮����һ���ո�\

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int a[N], b[N];

int pos;
int disc[N * 4];  //��Ϊ������λ��

int w[N * 4];
bool mp[N];

//�ҵ�xӳ��֮�������Ҳ����x���±�
int find(int x)
{
    int l = 1, r = pos;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(disc[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x, b[i] = y;
        //��ɢ��֮���п��ܵ���������С�����һ��λ��
        disc[++pos] = x, disc[++pos] = x + 1;
        disc[++pos] = y, disc[++pos] = y + 1;
    }

    //��ɢ��
    sort(disc + 1, disc + 1 + pos);
    pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);

    //����ɢ��֮���ֵ��������
    for(int i = 1; i <= m; i++)
    {
        int x = find(a[i]), y = find(b[i]);
        for(int j = x; j <= y; j++) w[j] = i;
    }

    //ͳ�����������У�һ���ж��ٸ���ͬ����
    int cnt = 0;
    for(int i = 1; i <= pos; i++)
    {
        int x = w[i];
        if(!x) continue;  //��Ҫͳ��0
        if(mp[x]) continue;
        cnt++;
        mp[x] = true;
    }

    cout << cnt << endl;

    return 0;
}
