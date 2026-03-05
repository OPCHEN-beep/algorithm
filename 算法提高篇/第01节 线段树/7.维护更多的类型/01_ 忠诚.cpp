// # P1816 忠诚

// ## 题目描述

// 老管家是一个聪明能干的人。他为财主工作了整整 $10$ 年。财主为了让自已账目更加清楚，要求管家每天记  $k$ 次账。由于管家聪明能干，因而管家总是让财主十分满意。

// 但是由于一些人的挑拨，财主还是对管家产生了怀疑。于是他决定用一种特别的方法来判断管家的忠诚。他把每次的账目按 $1, 2, 3, \ldots$ 编号，然后不定时地问管家这样的问题：在 $a$ 到 $b$ 号账中最少的一笔是多少？

// 为了让管家没时间作假，他总是一次问多个问题。

// ## 输入格式

// 第一行输入两个数 $m, n$，表示有 $m$ 笔账和 $n$ 个问题。  
// 第二行输入 $m$ 个数，分别表示账目的钱数 $x_i$。  
// 接下来 $n$ 行分别输入 $n$ 个问题，每行 $2$ 个数字，分别表示开始的账目编号 $a$ 和结束的账目编号 $b$。

// ## 输出格式

// 第一行输出每个问题的答案，每个答案中间以一个空格分隔。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 10 3
// 1 2 3 4 5 6 7 8 9 10
// 2 7
// 3 9
// 1 10
// ```

// ### 输出 #1

// ```
// 2 3 1
// ```

// ## 说明/提示

// 对于 $100\%$ 的数据，$1 \leq m \leq 10^5$，$1 \leq n \leq 10^5$，$0 \le x_i \le 10^5$。

#include <iostream>

using namespace std;

#define lc p << 1
#define rc p << 1 | 1

const int N = 1e5 + 10;

int n, m;
int a[N];

struct node
{
    int l, r;
    int min;
}tr[N << 2];

void build(int p, int l, int r)
{
    tr[p] = {l, r, a[l]};
    if(l == r) return;

    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    tr[p].min = min(tr[lc].min, tr[rc].min);
}

int query(int p, int x, int y)
{
    int l = tr[p].l, r = tr[p].r;
    if(x <= l && r <= y) return tr[p].min;

    int mid = (l + r) >> 1;
    int ret = 1e9;
    if(x <= mid) ret = min(ret, query(lc, x, y));
    if(y > mid) ret = min(ret, query(rc, x, y));
    return ret;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) ciin >> a[i];

    build(1, 1, n);

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        cout << query(1, x, y) << " ";
    }

    return 0;
}