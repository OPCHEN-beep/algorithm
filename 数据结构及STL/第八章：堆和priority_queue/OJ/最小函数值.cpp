//# P2085 最小函数值
//
//## 题目描述
//
//有 $n$ 个函数，分别为 $F_1,F_2,\dots,F_n$。定义 $F_i(x)=A_ix^2+B_ix+C_i(x\in\mathbb N*)$。给定这些 $A_i$、$B_i$ 和 $C_i$，请求出所有函数的所有函数值中最小的 $m$ 个（如有重复的要输出多个）。
//
//## 输入格式
//
//第一行输入两个正整数 $n$ 和 $m$。  
//
//以下 $n$ 行每行三个正整数，其中第 $i$ 行的三个数分别为 $A_i$、$B_i$ 和 $C_i$。
//
//## 输出格式
//
//输出将这 $n$ 个函数所有可以生成的函数值排序后的前 $m$ 个元素。这 $m$ 个数应该输出到一行，用空格隔开。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 10
//4 5 3
//3 4 5
//1 7 1
//```
//
//### 输出 #1
//
//```
//9 12 12 19 25 29 31 44 45 54
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//对于全部的测试点，保证 $1 \leq n,m\le10000$，$1 \leq A_i\le10$,
//$0 \leq B_i\le100$,
//$0 \leq C_i\le10^4$。

#include <iostream>
#include <queue>

using namespace std;

const int N = 1e4 + 10;
typedef long long LL;
int n, m;
int a[N], b[N], c[N];


struct Node
{
    LL f;
    int num;
    int x;

    bool operator<(const Node& x) const
    {
        //小根堆，大的元素下坠
        return f > x.f;
    }
};

priority_queue<Node> heap;

LL calc(LL i, LL x)
{
    return a[i] * x * x + b[i] * x + c[i];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }

    //1.把x = 1的值放入堆中
    for(int i = 1; i <= n; i++)
    {
        heap.push({calc(i, 1), i, 1});
    }

    //2.依次拿出m个值
    while(m--)
    {
        auto t = heap.top();
        heap.pop();
        int f = t.f, num = t.num, x = t.x;

        cout << f << " ";

        //把下一个函数值放入堆中
        heap.push({calc(num, x + 1), num, x + 1});
    }

    return 0;
}
