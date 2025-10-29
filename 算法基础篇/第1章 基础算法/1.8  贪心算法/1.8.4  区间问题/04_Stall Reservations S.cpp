//# P2859 [USACO06FEB] Stall Reservations S
//
//## 题目描述
//
//约翰的 $N$（$1\leq N\leq 50000$）头奶牛实在是太难伺候了，她们甚至有自己独特的产奶时段。对于某一头奶牛，她每天的产奶时段是固定的时间段 $[A,B]$（即 $A$ 到 $B$，包括 $A$ 和 $B$）($1 \leq A \leq B \leq 10^6$)。这使得约翰必须开发一个调控系统来决定每头奶牛应该被安排到哪个牛棚去挤奶，因为奶牛们并不希望在挤奶时被其它奶牛看见。
//
//请帮约翰计算：如果要满足奶牛们的要求，并且每天每头奶牛都要被挤过奶，至少需要多少牛棚和每头牛应该在哪个牛棚被挤奶。如果有多种答案，输出任意一种均可。
//
//## 输入格式
//
//第 $1$ 行，一个整数 $N$。
//
//第 $2\sim (N+1)$ 行，每行两个数字，第 $(i+1)$ 行的数字代表第 $i$ 头奶牛的产奶时段。
//
//## 输出格式
//
//第 $1$ 行输出一个整数，代表需要牛棚的最少数量。
//
//第 $2\sim (N+1)$ 行，每行一个数字，第 $(i+1)$ 行的数字代表第 $i$ 头奶牛将会被安排到哪个牛棚挤奶。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//1 10
//2 4
//3 6
//5 8
//4 7
//```
//
//### 输出 #1
//
//```
//4
//1
//2
//3
//2
//4
//```
//
//## 说明/提示
//
//由 @FlierKing 提供 SPJ。

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;

int n;
struct node
{
    //存一头牛的信息：开始时间、结束时间、排序之前的文职，分配的牛棚号
    int x, y, pos, num;
}a[N];

int cnt;
int ret[N];

multimap<int, int> st;

bool cmp(node& x, node& y)
{
    return x.x < y.x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].pos = i;
    } 
    
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        auto it = st.upper_bound(l);
// 不能接在任何?个区间后?，那就新开?个区间
        if(it == st.end())
        {
            st.insert({r, ++cnt});
            a[i].num = cnt;
        } 
        
        else // 能接在某个区间后?，那就接上去
        {
            int p = it->second;
            st.erase(it); // 把之前?删掉
            st.insert({r, p}); // 新来的?放进去
            a[i].num = p;
        }
    } 
    
    cout << cnt << endl;
    for(int i = 1; i <= n; i++)
    {
        ret[a[i].pos] = a[i].num;
    } 
    
    for(int i = 1; i <= n; i++) cout << ret[i] << endl;


    return 0;
}
