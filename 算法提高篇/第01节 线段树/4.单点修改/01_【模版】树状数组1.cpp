//# P3374 【模板】树状数组 1
//
//## 题目描述
//
//如题，已知一个数列，你需要进行下面两种操作：
//
//- 将某一个数加上 $x$；
//
//- 求出某区间每一个数的和。
//
//## 输入格式
//
//第一行包含两个正整数 $n,m$，分别表示该数列数字的个数和操作的总个数。   
// 
//第二行包含 $n$ 个用空格分隔的整数，其中第 $i$ 个数字表示数列第 $i$ 项的初始值。
//
//接下来 $m$ 行每行包含 $3$ 个整数，表示一个操作，具体如下：
//
//- `1 x k`  含义：将第 $x$ 个数加上 $k$；
//
//- `2 x y`  含义：输出区间 $[x,y]$ 内每个数的和。
//
//## 输出格式
//
//输出包含若干行整数，即为所有操作 $2$ 的结果。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5 5
//1 5 4 2 3
//1 1 3
//2 2 5
//1 3 -1
//1 4 2
//2 1 4
//```
//
//### 输出 #1
//
//```
//14
//16
//```
//
//## 说明/提示
//
//【数据范围】
//
//对于 $30\%$ 的数据，$1 \le n \le 8$，$1\le m \le 10$；   
//对于 $70\%$ 的数据，$1\le n,m \le 10^4$；   
//对于 $100\%$ 的数据，$1\le n,m \le 5\times 10^5$，$1\le x\le y\le n$，$-2^{31}\le k<2^{31}$。
//
//数据保证对于任意时刻，$a$ 的任意子区间（包括长度为 $1$ 和 $n$ 的子区间）和均在 $[-2^{31}, 2^{31})$ 范围内。
//
//
//样例说明：
//
// ![](https://cdn.luogu.com.cn/upload/pic/2256.png) 
//
//故输出结果 $14$ 和 $16$。

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
    LL sum;
}tr[N << 2];

void pushup(int p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, a[l]};
    if(l == r) return;

    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

//单点修改
void modify(int p, int x, LL k)
{
    int l = tr[p].l, r = tr[p].r;
    if(x == l && r == x)
    {
        tr[p].sum += k;
        return;
    }

    int mid = (l + r) >> 1;
    if(x <= mid) modify(lc, x, k);
    else modify(rc, x, k);
    pushup(p);
}

//区间查询
LL query(int p, int x, int y)
{
    int l = tr[p].l, r = tr[p].r;
    if(x <= l && r <= y) return tr[p].sum;

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
        if(op == 1)
        {
            modify(1, x, y);
        }
        else 
        {
            cout << query(1, x, y) << endl;
        }
    }

    return 0;
}
