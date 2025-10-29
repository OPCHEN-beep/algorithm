//# P1803 凌乱的yyy / 线段覆盖
//
//## 题目背景
//
//**Python 用户可以尝试使用 pypy3 提交试题。**
//
//快 noip 了，yyy 很紧张！
//
//## 题目描述
//
//现在各大 oj 上有 $n$ 个比赛，每个比赛的开始、结束的时间点是知道的。
//
//yyy 认为，参加越多的比赛，noip 就能考的越好（假的）。
//
//所以，他想知道他最多能参加几个比赛。
//
//由于 yyy 是蒟蒻，如果要参加一个比赛必须善始善终，而且不能同时参加 $2$ 个及以上的比赛。
//
//## 输入格式
//
//第一行是一个整数 $n$，接下来 $n$ 行每行是 $2$ 个整数 $a_{i},b_{i}\ (a_{i}<b_{i})$，表示比赛开始、结束的时间。
//
//## 输出格式
//
//一个整数最多参加的比赛数目。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//0 2
//2 4
//1 3
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
//- 对于 $20\%$ 的数据，$n \le 10$；
//- 对于 $50\%$ 的数据，$n \le 10^3$；
//- 对于 $70\%$ 的数据，$n \le 10^{5}$；
//- 对于 $100\%$ 的数据，$1\le n \le 10^{6}$，$0 \le a_{i} < b_{i} \le 10^6$。

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n;
PII a[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + 1 + n);  //默认按照首元素比较

    int r = a[1].second, ret = 1;
    for(int i = 2; i <= n; i++)
    {
        int x = a[i].first, y = a[i].second;
        if(r <= x)  //没有重叠
        {
            ret++;
            r = y;
        }
        else  //有重叠，就选右边界最小的那一个
        {
            r = min(r, y);
        }
    }

    cout << ret << endl;
    
    return 0;
}
