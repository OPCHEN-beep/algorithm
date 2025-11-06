//# SP1805 HISTOGRA - Largest Rectangle in a Histogram
//
//## 题目背景
//
//如遇 SPOJ 评测服务不稳定，可以在 <https://www.luogu.com.cn/problem/B4273> 评测本题，注意 $n$ 和 $h_i$ 范围的小变化。
//
//## 题目描述
//
//![](https://cdn.luogu.com.cn/upload/vjudge_pic/SP1805/b9567e3483620f1fe679470ac44083eae9842e79.png)
//
//如图所示，在一条水平线上有  $n$ 个宽为  $1$ 的矩形，求包含于这些矩形的最大子矩形面积（图中的阴影部分的面积即所求答案）。
//
//## 输入格式
//
//有多组测试数据，每组数据占一行。输入零时读入结束。
//
//每行开头为一个数字  $n(1\le n\le 10^5)$，接下来在同一行给出  $n$ 个数字  $h_1,h_2,\cdots, h_n (0\le h_i\le 10^9)$，表示每个矩形的高度。
//
//## 输出格式
//
//对于每组数据，输出最大子矩阵面积，一组数据输出一行。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//7 2 1 4 5 1 3 3
//4 1000 1000 1000 1000
//0
//```
//
//### 输出 #1
//
//```
//8
//4000
//```

#include <iostream>
#include <stack>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
LL h[N];
LL x[N], y[N];

int main()
{
    while(cin >> n, n)
    {
        for(int i = 1; i <= n; i++) cin >> h[i];

        //找左边，小
        stack<int> st;
        for(int i = 1; i <= n; i++)
        {
            while(st.size() && h[st.top()] >= h[i]) st.pop();

            if(st.size()) x[i] = st.top();
            else x[i] = 0;

            st.push(i);
        }

        //找右边，小
        while(st.size()) st.pop();

        for(int i = n; i >= 1; i--)
        {
            while(st.size() && h[st.top()] >= h[i]) st.pop();
            if(st.size()) y[i] = st.top();
            else y[i] = n + 1;

            st.push(i);
        }

        LL ret = 0;
        for(int i = 1; i <= n; i++)
        {
            ret = max(ret, h[i] * (y[i] - x[i] - 1));
        }

        cout << ret << endl;
    }

    return 0;
}
