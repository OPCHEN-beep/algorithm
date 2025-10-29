//# P1631 序列合并
//
//## 题目描述
//
//有两个长度为 $N$ 的**单调不降**序列 $A,B$，在 $A,B$ 中各取一个数相加可以得到 $N^2$ 个和，求这 $N^2$ 个和中最小的 $N$ 个。
//
//## 输入格式
//
//第一行一个正整数 $N$；
//
//第二行 $N$ 个整数 $A_{1\dots N}$。
//
//第三行 $N$ 个整数 $B_{1\dots N}$。
//
//## 输出格式
//
//一行 $N$ 个整数，从小到大表示这 $N$ 个最小的和。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//2 6 6
//1 4 8
//```
//
//### 输出 #1
//
//```
//3 6 7
//```
//
//## 说明/提示
//
//对于 $50\%$ 的数据，$N \le 10^3$。
//
//对于 $100\%$ 的数据，$1 \le N \le 10^5$，$1 \le a_i,b_i \le 10^9$。

#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N];

struct Node
{
    int sum;//当前的和
    int i, j;//a和b的编号

    bool operator <(const Node& x) const
    {
        //小根堆
        return sum > x.sum;
    }
};

priority_queue<Node> heap;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    //1.将a[i] + b[i]放进堆里面
    for(int i = 1; i <= n; i++)
    {
        heap.push({a[i] + b[1], i, 1});
    }

    //2.依次拿出n的数
    for(int k = 1; k <= n; k++)
    {
        Node t = heap.top();
        heap.pop();
        int sum = t.sum, i = t.i, j = t.j;

        cout << sum << " ";
        if(j + 1 <= n) heap.push({a[i] + b[j + 1], i, j + 1});
    }

    return 0;
}
