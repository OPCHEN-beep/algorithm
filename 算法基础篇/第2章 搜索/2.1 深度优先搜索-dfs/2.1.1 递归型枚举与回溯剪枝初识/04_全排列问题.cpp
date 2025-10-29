//# P1706 ȫ��������
//
//## ��Ŀ����
//
//�����ֵ��������Ȼ�� $1$ �� $n$ ���в��ظ������У��� $n$ ��ȫ���У�Ҫ������������һ���������в���������ظ������֡�
//
//## �����ʽ
//
//һ������ $n$��
//
//## �����ʽ
//
//�� $1 \sim n$ ��ɵ����в��ظ����������У�ÿ��һ�����С�
//
//ÿ�����ֱ��� $5$ ������
//
//## ����������� #1
//
//### ���� #1
//
//```
//3
//```
//
//### ��� #1
//
//```
//1    2    3
//    1    3    2
//    2    1    3
//    2    3    1
//    3    1    2
//    3    2    1
//```
//
//## ˵��/��ʾ
//
//$1 \leq n \leq 9$��

#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n;
bool st[N];
vector<int> path;

void dfs()
{
    if(path.size() == n)
    {
        for(auto x : path)
        {
            printf("%5d", x);
        }

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
    cin >> n;

    dfs();
    
    return 0;
}
