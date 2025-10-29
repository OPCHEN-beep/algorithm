//# P2887 [USACO07NOV] Sunscreen G
//
//## 题目描述
//
//有 $C$ 头奶牛进行日光浴，第 $i$ 头奶牛需要 $minSPF[i]$ 到 $maxSPF[i]$ 单位强度之间的阳光。
//
//每头奶牛在日光浴前必须涂防晒霜，防晒霜有 $L$ 种，涂上第 $i$ 种之后，身体接收到的阳光强度就会稳定为 $SPF[i]$，第 $i$ 种防晒霜有 $cover[i]$ 瓶。
//
//求最多可以满足多少头奶牛进行日光浴。
//
//## 输入格式
//
//第一行输入整数 $C$ 和 $L$。
//
//接下来的 $C$ 行，按次序每行输入一头牛的 $minSPF$ 和 $maxSPF$ 值，即第 $i$ 行输入 $minSPF[i]$ 和 $maxSPF[i]$。
//
//再接下来的 $L$ 行，按次序每行输入一种防晒霜的 $SPF$ 和 $cover$ 值，即第 $i$ 行输入 $SPF[i]$ 和 $cover[i]$。
//
//每行的数据之间用空格隔开。
//
//## 输出格式
//
//输出一个整数，代表最多可以满足奶牛日光浴的奶牛数目。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 2
//3 10
//2 5
//1 5
//6 2
//4 1
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 说明/提示
//
//样例解释：给第一头奶牛涂第一种防晒霜，第二头奶牛涂第二种防晒霜。
//
//
//---
//
//
//对于 $100\%$ 的数据，$1\le C,L\le 2500$，$1\le minSPF[i]\le maxSPF[i]\le 1000$，$1\le SPF[i]\le 1000$，$1\le cover[i]\le 2500$。

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;

int n, m;

struct node
{
    int x, y;
}a[N], b[N];

bool cmp1(node& x, node& y)
{
    return x.y < y.y;
}

bool cmp2(node& x, node& y)
{
    return x.x < y.x;
}

bool cmp3(node& x, node& y)
{
    return x.x > y.x;
}

//所有区间按照右端点从小到大排序
//所有点按照从小到大排序
void solve1()
{
    sort(a + 1, a + 1 + n, cmp1);
    sort(b + 1, b + 1 + m, cmp2);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        for(int j = 1; j <= m; j++)
        {
            //选一个最小的，符合要求的点
            int &sp = b[j].x, &cnt = b[j].y;
            if(!cnt || sp < l) continue;
            if(sp > r) break;
            cnt--;
            ret++;
            break;
        }
    }

    cout << ret << endl;
}

//所有区间按照左端点从大到小排序
//所有点按照从大到小排序
void solve2()
{
    sort(a + 1, a + 1 + n, cmp3);
    sort(b + 1, b + 1 + m, cmp3);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = a[i].x, r = a[i].y;
        for(int j = 1; j <= m; j++)
        {
            //选一个最大的、符合要求的点
            int &sp = b[j].x, &cnt = b[j].y;
            if(!cnt || sp > r) continue;
            if(sp < l) break;
            ret++;
            cnt--;
            break;
        }
    }

    cout << ret << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for(int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;

    //solve1();  //按照右端点排序
    solve2();  //按照左端点排序

    return 0;
}
