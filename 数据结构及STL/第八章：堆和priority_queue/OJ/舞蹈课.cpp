//# P1878 舞蹈课
//
//## 题目描述
//
//有 $n$ 个人参加一个舞蹈课。每个人的舞蹈技术由整数来决定。在舞蹈课的开始，他们从左到右站成一排。当这一排中至少有一对相邻的异性时，舞蹈技术相差最小的那一对会出列并开始跳舞。如果不止一对，那么最左边的那一对出列。一对异性出列之后，队伍中的空白按原顺序补上（即：若队伍为 `ABCD`，那么 `BC` 出列之后队伍变为 `AD`）。舞蹈技术相差最小即是 $a_i$ 的绝对值最小。
//
//任务是模拟以上过程，确定跳舞的配对及顺序。
//
//## 输入格式
//
//第一行一个正整数 $n$ 表示队伍中的人数。
//
//第二行包含 $n$ 个字符 `B` 或者 `G`，`B` 代表男，`G` 代表女。
//
//第三行为 $n$ 个整数 $a_i$。所有信息按照从左到右的顺序给出。
//
//## 输出格式
//
//第一行一个整数表示出列的总对数 $k$。
//
//接下来 $k$ 行，每行是两个整数。按跳舞顺序输出，两个整数代表这一对舞伴的编号（按输入顺序从左往右 $1$ 至 $n$ 编号）。请先输出较小的整数，再输出较大的整数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4
//BGBG
//4 2 4 3
//```
//
//### 输出 #1
//
//```
//2
//3 4
//1 2
//```
//
//## 说明/提示
//
//对于 $50\%$ 的数据，$1\leq n\leq 200$。
//
//对于 $100\%$ 的数据，$1\leq n\leq 2\times 10^5$，$0\le a_i\le 10^7$。

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;

int n;
int s[N];//标记男/女 - 0/1

//双向链表存数据
int e[N];
int pre[N], ne[N];

struct node
{
    int d;//技术差
    int l, r;//左右编号

    //小根堆
    bool operator<(const node& x) const
    {
        if(d != x.d) return d > x.d;
        else if(l != x.l) return l > x.l;
        else return r > x.r;
    }
};

priority_queue<node> heap;
bool st[N];//标记已经出队的人

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if(ch == 'B')
            s[i] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> e[i];
        //创建双向链表
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = ne[n] = 0;//0表示后面没有元素

    //1.先把所有的异性差放进堆中
    for(int i = 2; i <= n; i++)
    {
        if(s[i] != s[i - 1])
        {
            heap.push({abs(e[i] - e[i - 1]), i - 1, i});
        }
    }

    //2.提取结果
    vector<node> ret;//暂存结果

    while(heap.size())
    {
        node t = heap.top();
        heap.pop();
        int d = t.d, l = t.l, r = t.r;

        if(st[l] || st[r]) continue;

        ret.push_back(t);
        st[l] = st[r] = true;

        //修改指针，还原新的队列
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];

        //判断新的左右是否会成为一对
        int left = pre[l], right = ne[r];
        if(left && right && s[left] != s[right])
        {
            heap.push({abs(e[left] - e[right]), left, right});
        }
    }

    cout << ret.size() << endl;
    for(auto& x : ret)
    {
        cout << x.l << " " << x.r << endl;
    }

    return 0;
}#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;

int n;
int s[N];//标记男/女 - 0/1

//双向链表存数据
int e[N];
int pre[N], ne[N];

struct node
{
    int d;//技术差
    int l, r;//左右编号

    //小根堆
    bool operator<(const node& x) const
    {
        if(d != x.d) return d > x.d;
        else if(l != x.l) return l > x.l;
        else return r > x.r;
    }
};

priority_queue<node> heap;
bool st[N];//标记已经出队的人

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if(ch == 'B')
            s[i] = 1;
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> e[i];
        //创建双向链表
        pre[i] = i - 1;
        ne[i] = i + 1;
    }
    pre[1] = ne[n] = 0;//0表示后面没有元素

    //1.先把所有的异性差放进堆中
    for(int i = 2; i <= n; i++)
    {
        if(s[i] != s[i - 1])
        {
            heap.push({abs(e[i] - e[i - 1]), i - 1, i});
        }
    }

    //2.提取结果
    vector<node> ret;//暂存结果

    while(heap.size())
    {
        node t = heap.top();
        heap.pop();
        int d = t.d, l = t.l, r = t.r;

        if(st[l] || st[r]) continue;

        ret.push_back(t);
        st[l] = st[r] = true;

        //修改指针，还原新的队列
        ne[pre[l]] = ne[r];
        pre[ne[r]] = pre[l];

        //判断新的左右是否会成为一对
        int left = pre[l], right = ne[r];
        if(left && right && s[left] != s[right])
        {
            heap.push({abs(e[left] - e[right]), left, right});
        }
    }

    cout << ret.size() << endl;
    for(auto& x : ret)
    {
        cout << x.l << " " << x.r << endl;
    }

    return 0;
}
