//# P5250 �����17.��5��ľ�Ĳֿ�
//
//## ��Ŀ����
//
//��������һ��ľ�Ĳֿ⣬������Դ洢���ֳ��ȵ�ľ�ģ����Ǳ�֤û������ľ�ĵĳ�������ͬ�ġ���Ϊ�ֿ⸺���ˣ�����ʱ����������ʱ�������������Ҫά�������档�в����� $10^5$ ���Ĳ�����
//
//- ��������ʽ `1 Length`���ڲֿ��з���һ������Ϊ $Length$�������� $10^9$����ľ�ġ�����Ѿ�����ͬ���ȵ�ľ����ô��� `Already Exist`��
//- ��������ʽ `2 Length`���Ӳֿ���ȡ������Ϊ $Length$ ��ľ�ġ����û�иպó��ȵ�ľ�ģ�ȡ���ֿ��д��ڵĺ�Ҫ�󳤶���ӽ���ľ�ġ�����ж��ľ�ķ���Ҫ��ȡ���Ƚ϶̵�һ�������ȡ����ľ�ĳ��ȡ�����ֿ��ǿյģ���� `Empty`��
//
//## �����ʽ
//
//��һ��һ���� $m$ �������������
//
//������ $m$ �У�ÿ��һ�β�������ʽ����Ŀ������ʾ��
//
//## �����ʽ
//
//����ÿ�β�����������Ŀ����Ҫ������𰸡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//7
//1 1
//1 5
//1 3
//2 3
//2 3
//2 3
//2 3
//```
//
//### ��� #1
//
//```
//3
//1
//5
//Empty
//```

#include <iostream>
#include <set>

using namespace std;

typedef long long LL;

const LL INF = 1e10 + 10;

set<LL> mp;

int main()
{
    int q;
    cin >> q;
    //���һ���������߽����
    mp.insert(-INF);
    mp.insert(INF);

    while(q--)
    {
        LL op, len;
        cin >> op >> len;

        if(op == 1)//����
        {
            if(mp.count(len))
                cout << "Already Exist" << endl;
            else
                mp.insert(len);
        }
        else
        {
            if(mp.size() == 2)
            {
                cout << "Empty" << endl;
            }
            else{
                //�ҵ�����len�������һ��
                auto it = mp.lower_bound(len);
                auto tmp = it;
                tmp--;

                if(abs(*tmp - len) <= abs(*it - len))
                {
                    cout << *tmp << endl;
                    mp.erase(tmp);
                }
                else
                {
                    cout << *it << endl;
                    mp.erase(it);
                }
            }
            
        }
    }
}
