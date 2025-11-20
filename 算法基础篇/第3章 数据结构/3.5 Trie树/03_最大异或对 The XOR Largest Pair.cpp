//# P10471 最大异或对 The XOR Largest Pair
//
//## 题目描述
//
//给定 $N$ 个整数 $A_1.A_2, \cdots, A_N$ 中选出两个进行异或计算，得到的结果最大是多少？
//
//## 输入格式
//
//第一行一个整数 $N$，第二行 $N$ 个整数 $A_1.A_2, \cdots, A_N$。
//
//## 输出格式
//
//一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//1 2 3
//```
//
//### 输出 #1
//
//```
//3
//```
//
//## 说明/提示
//
//对于所有测试数据，$1 \le N \le 10^5$，保证 $0\le A_i<2^{31}$。

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int tr[N * 32][2], idx;

void insert(int x)
{
    int cur = 0;
    for(int i = 31; i >= 0; i--)
    {
        int path = ((x >> i) & 1);
        if(tr[cur][path] == 0) tr[cur][path] = ++idx;
        cur = tr[cur][path];
    }
}

int find(int x)
{
    int cur = 0;
    int ret = 0;
    for(int i = 31; i >= 0; i--)
    {
        int path = ((x >> i) & 1);

        //贪心思想——要去相反的路
        if(tr[cur][path ^ 1])
        {
            ret |= (1 << i);
            cur = tr[cur][path ^ 1];
        }

        else
        {
            cur = tr[cur][path];
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        ret = max(ret, find(a[i]));
    }

    cout << ret << endl;

    return 0;
}
