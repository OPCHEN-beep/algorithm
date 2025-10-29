//# P1305 新二叉树
//
//## 题目描述
//
//输入一串二叉树，输出其前序遍历。
//
//## 输入格式
//
//第一行为二叉树的节点数 $n$。($1 \leq n \leq 26$)
//
//后面 $n$ 行，每一个字母为节点，后两个字母分别为其左右儿子。特别地，数据保证第一行读入的节点必为根节点。
//
//空节点用 `*` 表示
//
//## 输出格式
//
//二叉树的前序遍历。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//6
//abc
//bdi
//cj*
//d**
//i**
//j**
//```
//
//### 输出 #1
//
//```
//abdicj
//```

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
char root;
char l[N], r[N];

void dfs(char root)
{
    if(root == '*')
        return;
    cout << root;
    dfs(l[root]);
    dfs(r[root]);
}

int main()
{
    cin >> n;
    cin >> root;
    cin >> l[root] >> r[root];
    
    for(int i = 2; i <= n; i++)
    {
        char t;
        cin >> t;
        cin >> l[t] >> r[t];
    }

    dfs(root);

    return 0;
}
