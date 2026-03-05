// # P3368 【模板】树状数组 2

// ## 题目描述

// 如题，已知一个数列，你需要进行下面两种操作：

// 1. 将某区间每一个数加上 $x$；

// 2. 求出某一个数的值。

// ## 输入格式

// 第一行包含两个整数 $N$、$M$，分别表示该数列数字的个数和操作的总个数。

// 第二行包含 $N$ 个用空格分隔的整数，其中第 $i$ 个数字表示数列第 $i $ 项的初始值。

// 接下来 $M$ 行每行包含 $2$ 或 $4$ 个整数，表示一个操作，具体如下：

// 操作 $1$： 格式：`1 x y k` 含义：将区间 $[x,y]$ 内每个数加上 $k$；

// 操作 $2$： 格式：`2 x` 含义：输出第 $x$ 个数的值。

// ## 输出格式

// 输出包含若干行整数，即为所有操作 $2$ 的结果。

// ## 输入输出样例 #1

// ### 输入 #1

// ```
// 5 5
// 1 5 4 2 3
// 1 2 4 2
// 2 3
// 1 1 5 -1
// 1 3 5 7
// 2 4
// ```

// ### 输出 #1

// ```
// 6
// 10
// ```

// ## 说明/提示

// #### 样例 1 解释：

//  ![](https://cdn.luogu.com.cn/upload/pic/2258.png) 

// 故输出结果为 $6$ 和 $10$。

// ---

// #### 数据规模与约定

// 对于 $30\%$ 的数据：$N\le8$，$M\le10$；

// 对于 $70\%$ 的数据：$N\le 10^4$，$M\le10^4$；

// 对于 $100\%$ 的数据：$1 \leq N, M\le 5\times10^5$，$1 \leq x, y \leq n$，保证任意时刻序列中任意元素的绝对值都不大于 $2^{30}$。

#include <iostream>
using namespace std;

#define lc p << 1
#define rc p << 1 | 1
typedef long long LL;

const int N = 5e5 + 10;

int n, m;
LL a[N];

struct node
{
    int l, r;
    LL sum, add;
}tr[N << 2];

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
    lazy(lc, tr[p].add);
    lazy(rc, tr[p].add);
    tr[p].add = 0;
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

//单点查询
LL query(int p, int x)
{
    int l = tr[p].l, r = tr[p].r;
    if(l == x && x == r) return tr[p].sum;

    pushdown(p);
    int mid = (l + r) >> 1;
    if(x <= mid) return query(lc, x);
    else return query(rc, x);
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while(m--)
    {
        int op, x, y;
        LL k;
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y >> k;
            modify(1, x, y, k);
        }
        else
        {
            cin >> x;
            cout << query(1, x) << endl;
        }
    }

    return 0;
}