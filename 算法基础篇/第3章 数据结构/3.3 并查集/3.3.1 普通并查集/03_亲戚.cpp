//# P1551 亲戚
//
//## 题目背景
//
//若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。
//
//## 题目描述
//
//规定：$x$ 和 $y$ 是亲戚，$y$ 和 $z$ 是亲戚，那么 $x$ 和 $z$ 也是亲戚。如果 $x$，$y$ 是亲戚，那么 $x$ 的亲戚都是 $y$ 的亲戚，$y$ 的亲戚也都是 $x$ 的亲戚。
//
//## 输入格式
//
//第一行：三个整数 $n,m,p$，（$n,m,p \le 5000$），分别表示有 $n$ 个人，$m$ 个亲戚关系，询问 $p$ 对亲戚关系。
//
//以下 $m$ 行：每行两个数 $M_i$，$M_j$，$1 \le M_i,~M_j\le n$，表示 $M_i$ 和 $M_j$ 具有亲戚关系。
//
//接下来 $p$ 行：每行两个数 $P_i,P_j$，询问 $P_i$ 和 $P_j$ 是否具有亲戚关系。
//
//## 输出格式
//
//$p$ 行，每行一个 `Yes` 或 `No`。表示第 $i$ 个询问的答案为“具有”或“不具有”亲戚关系。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//6 5 3
//1 2
//1 5
//3 4
//5 2
//1 3
//1 4
//2 3
//5 6
//```
//
//### 输出 #1
//
//```
//Yes
//Yes
//No
//```

#include <iostream>

using namespace std;

const int N = 5010;

int n, m, p;
int fa[N];

int find(int x)
{
    return fa[x] == x ? x : find(fa[x]);
}

void un(int x, int y)
{
    int fx = find(x), fy = find(y);
    fa[fy] = fx;
}

bool issame(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    cin >> n >> m >> p;

    //初始化
    for(int i = 1; i <= n; i++) fa[i] = i;

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        un(x, y);
    }

    while(p--)
    {
        int x, y;
        cin >> x >> y;
        if(issame(x, y)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
