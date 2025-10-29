//# P3884 [JLOI2009] ����������
//
//## ��Ŀ����
//
//����ͼ��ʾ��һ�ö���������ȡ���ȼ��������ֱ�Ϊ��
//
//- ��ȣ�$4$
//- ��ȣ�$4$
//- ��� 8 �� 6 ֮��ľ��룺$8$
//- ��� 7 �� 6 ֮��ľ��룺$3$
//
//���п�ȱ�ʾ��������ͬһ�����Ľ��������ڵ� $u, v$ ֮��ľ����ʾ�� $u$ �� $v$ ���������·��������ڵ�ı���������������Ҷ�ڵ�ı�����
//
//![](https://cdn.luogu.com.cn/upload/pic/6843.png)
//
//����һ���� 1 �Ž��Ϊ���Ķ����������������ȡ���Ⱥ�����ָ���ڵ� $x, y$ ֮��ľ��롣
//
//## �����ʽ
//
//��һ����һ����������ʾ���Ľ����� $n$��  
//������ $n - 1$ �У�ÿ���������� $u, v$����ʾ���ϴ���һ������ $u, v$ �ıߡ�  
//���һ������������ $x, y$����ʾ�� $x, y$ ֮��ľ��롣
//
//## �����ʽ
//
//������У�ÿ��һ�����������α�ʾ����������ȡ���Ⱥ� $x, y$ ֮��ľ��롣
//
//## ����������� #1
//
//### ���� #1
//
//```
//10                                
//1 2                            
//1 3                            
//2 4
//2 5
//3 6
//3 7
//5 8
//5 9
//6 10
//8 6
//```
//
//### ��� #1
//
//```
//4
//4
//8
//```
//
//## ˵��/��ʾ
//
//����ȫ���Ĳ��Ե㣬��֤ $1 \leq u, v, x, y \leq n \leq 100$���Ҹ�������һ��������֤ $u$ �� $v$ �ĸ���㡣

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 110;

int n;
vector<int> edges[N];

int fa[N];//i�ĸ���
int dist[N];//i��x����̾���

//�����
int dfs(int u)
{
    int ret = 0;
    for(auto v : edges[u])
    {
        ret = max(ret, dfs(v));
    }
    return ret + 1;
}

//����
int bfs()
{
    queue<int> q;
    q.push(1);

    int ret = 0;

    while(q.size())
    {
        int sz = q.size();
        ret = max(ret, sz);

        while(sz--)
        {
            int u = q.front();
            q.pop();
            for(auto v : edges[u])
            {
                q.push(v);
            }
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        edges[u].push_back(v);

        fa[v] = u;
    }

    //�����
    cout << dfs(1) << endl;

    //����
    cout << bfs() << endl;

    //�����
    int x, y;
    cin >> x >> y;
    while(x != 1)
    {
        dist[fa[x]] = dist[x] + 1;
        x = fa[x];
    }

    int len = 0;
    while(y != 1 && dist[y] == 0)
    {
        len++;
        y = fa[y];
    }

    cout << dist[y] * 2 + len << endl;

    return 0;
}
