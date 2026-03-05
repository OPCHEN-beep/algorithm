// # P3372 【模板】线段树 1

// ## 题目描述

// 如题，已知一个数列 $\{a_i\}$，你需要进行下面两种操作：

// 1. 将某区间每一个数加上 $k$。
// 2. 求出某区间每一个数的和。

// ## 输入格式

// 第一行包含两个整数 $n, m$，分别表示该数列数字的个数和操作的总个数。

// 第二行包含 $n$ 个用空格分隔的整数 $a_i$，其中第 $i$ 个数字表示数列第 $i$ 项的初始值。

// 接下来 $m$ 行每行包含 $3$ 或 $4$ 个整数，表示一个操作，具体如下：

// 1. `1 x y k`：将区间 $[x, y]$ 内每个数加上 $k$。
// 2. `2 x y`：输出区间 $[x, y]$ 内每个数的和。

// ## 输出格式

// 输出包含若干行整数，即为所有操作 2 的结果。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 5 5
// 1 5 4 2 3
// 2 2 4
// 1 2 3 2
// 2 3 4
// 1 1 5 1
// 2 1 4
// ```

// ### 输出 #1

// ```
// 11
// 8
// 20
// ```

// ## 说明/提示

// 对于 $15\%$ 的数据：$n \le 8$，$m \le 10$。  
// 对于 $35\%$ 的数据：$n \le {10}^3$，$m \le {10}^4$。    
// 对于 $100\%$ 的数据：$1 \le n, m \le {10}^5$，$a_i,k$ 为正数，且任意时刻数列的和不超过 $2\times 10^{18}$。

// **【样例解释】**

// ![](https://cdn.luogu.com.cn/upload/pic/2251.png)

#include <iostream>
using namespace std;

#define lc p << 1
#define rc p << 1 | 1
typedef long long LL;

const int N = 1e5 + 10;

int n, m;
LL a[N];

struct node
{
    int l, r;
    LL sum, add;
}tr[N * 4];

void lazy(int p, LL k)
{
    tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
    tr[p].add += k;
}

void pushup(int p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p)
{
    if(tr[p].add)
    {
        lazy(lc, tr[p].add);
        lazy(rc, tr[p].add);
        tr[p].add = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, a[l], 0};
    if(l == r) return;

    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

//区间修改
void modify(int p, int x, int y, LL k)
{
    int l = tr[p].l, r = tr[p].r;
    if(x <= l && r <= y)
    {
        lazy(p, k);
        return;
    }

    pushdown(p);
    int mid = (l + r) >> 1;
    if(x <= mid) modify(lc, x, y, k);
    if(y > mid) modify(rc, x, y, k);
    pushup(p);
}

//区间查询
LL query(int p, int x, int y)
{
    int l = tr[p].l, r = tr[p].r;
    if(x <= l && r <= y) return tr[p].sum;

    pushdown(p);
    int mid = (l + r) >> 1;
    LL sum = 0;
    if(x <= mid) sum += query(lc, x, y);
    if(y > mid) sum += query(rc, x, y);
    return sum;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while(m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        LL k;
        if(op == 1)
        {
            cin >> k;
            modify(1, x, y, k);
        }
        else
        {
            cout << query(1, x, y) << endl;
        }
    }

    return 0;
}