//# UVA1193 Radar Installation
//
//## ��Ŀ����
//
//[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=246&page=show_problem&problem=3634
//
//[PDF](https://uva.onlinejudge.org/external/11/p1193.pdf)
//
//������
//���躣������һ�����޳���ֱ�ߣ�½��λ�ں����ߵ�һ�ߣ���λ�ں����ߵ���һ�ߡ����������С����ĳ��ȫ����Ϊ�˼�����Щ�����Ƿ��е������֣������ں������ϰ�װ���ɸ��״�����⵺��������ÿ���״�ĸ��Ƿ�Χ�����״�����ΪԲ�ģ��뾶Ϊ d ��Բ������
//
//������ƽ��֮������ϵ����ʾ�������򣬺�����Ϊ x �ᣬ��λ�� x ���Ϸ���½��λ�� x ���·���Ϊ�˽�Լ�ɱ�����ȫ������ʹ�����ٵ��״︲�����еĵ��졣������֪ÿ����������� (x,y) ���״�ĸ��ǰ뾶 d�����������Ǽ�����ܹ��������е���������״�������
//
//���룺
//����������������ݡ�
//
//ÿ�����ݵĵ�һ������������ n(1��n��1000) �� d���ֱ��ʾ������������״�ĸ��ǰ뾶��֮��� n �У�ÿ����������������ʾ�� i ����������� (x 
//i
//?
// ,y 
//i
//?
// )��
//
//���ڵ���������ʹ��һ�����и��������� 0 0 ��ʾ���������
//
//�����
//����ÿһ�����ݵ������ʽΪ Case i: x����ʾ�� i ��������������Ҫ x ���״����������еĵ��죻x=?1 ��ʾ���������޽⣨�޷��������еĵ��죩

//## �����ʽ
//
//��
//
//## �����ʽ
//
//��
//
//## ����������� #1
//
//### ���� #1
//
//```
//3 2
//1 2
//-3 1
//2 1
//
//1 2
//0 2
//
//0 0
//```
//
//### ��� #1
//
//```
//Case 1: 2
//Case 2: 1
//```

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, d;

struct node
{
    double l, r;
}a[N];

bool cmp(node& x, node& y)
{
    return x.l < y.l;
}

int main()
{
    int cnt = 0;
    while(cin >> n >> d, n && d)
    {
        cnt++;
        bool flag = false;//�п��ܵ���̫Զ���������Ҳ���ǲ���
        for(int i = 1; i <= n; i++)
        {
            double x, y;
            cin >> x >> y;
            if(y > d) flag == true;
            else
            {
                double t = sqrt(d * d - y * y);
                a[i].l = x - t, a[i].r = x + t;
            }
        }

        cout << "Case " << cnt << ": ";
        if(flag) cout << -1 << endl;
        else
        {
            sort(a + 1, a + 1 + n, cmp);
            int ret = 1;
            double r = a[1].r;
            for(int i = 2; i <= n; i++)
            {
                double x = a[i].l, y = a[i].r;
                if(x > r)  //û���ص�
                {
                    ret++;
                    r = y;
                }
                else
                {
                    //���ص�
                    r = min(r, y);
                }
            }

            cout << ret << endl;
        }
    }

    return 0;
}
