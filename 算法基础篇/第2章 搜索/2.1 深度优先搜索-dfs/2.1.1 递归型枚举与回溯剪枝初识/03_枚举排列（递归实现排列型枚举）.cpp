//# B3623 ö�����У��ݹ�ʵ��������ö�٣�
//
//## ��Ŀ����
//
//���� $n$ ��ѧ����Ҫ����ѡ�� $k$ ���ų�һ�����ա�
//
//�밴�ֵ���������п��ܵ����з�ʽ��
//
//## �����ʽ
//
//��һ�У����������� $n, k$��
//
//## �����ʽ
//
//�����У�ÿ�� $k$ ������������ʾһ�ֿ��ܵĶ���˳��
//
//## ����������� #1
//
//### ���� #1
//
//```
//3 2
//```
//
//### ��� #1
//
//```
//1 2
//1 3
//2 1
//2 3
//3 1
//3 2
//```
//
//## ˵��/��ʾ
//
//���� $100\%$ �����ݣ�$1\leq k\leq n \leq 10$��

#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, k;
vector<int> path;
bool st[N];  //���һ����Щ���Ѿ�ѡ����
void dfs()
{
    if(path.size() == k)
    {
        for(auto x : path) cout << x << " ";
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(st[i]) continue;
        path.push_back(i);
        st[i] = true;
        dfs();
        //�ָ��ֳ�
        path.pop_back();
        st[i] = false;
    }
}

int main()
{
    cin >> n >> k;

    dfs();

    return 0;
}
