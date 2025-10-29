//# P1923 【深基9.例4】求第 k 小的数
//
//## 题目描述
//
//输入 $n$（$1 \le n < 5000000$ 且 $n$ 为奇数）个数字 $a_i$（$1 \le a_i < {10}^9$），输出这些数字的第 $k$ 小的数。最小的数是第 $0$ 小。
//
//请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。
//
//## 输入格式
//
//第一行有两个整数，分别表示 $n$ 和 $k$。
//
//第二行有 $n$ 个整数，第 $i$ 个数表示 $a_i$。
//
//## 输出格式
//
//一个整数，表示第 $k$ 小的数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5 1
//4 3 2 1 5
//```
//
//### 输出 #1
//
//```
//2
//```

#include <iostream>
#include <ctime>

using namespace std;

const int N = 5e6 + 10;

int n, k;
int a[N];

//[l, r]之间随机返回一个数
int get_random(int l, int r)
{
    return a[rand() % (r - l + 1) + l];
}

int quick_select(int l, int r, int k)
{
    if(l == r) return a[l];

    //随机选择基准元素
    int p = get_random(l, r);

    //以p为基准划分三部分
    int x = l - 1, y = r + 1, i = l;
    while(i < y)
    {
        if(a[i] == p) i++;
        else if(a[i] < p) swap(a[++x], a[i++]);
        else swap(a[--y], a[i]);

        //[l, x][x + 1, y - 1][y, r]
        int c1 = x - l + 1, c2 = y - 1 - x, c3 = r - y + 1;
        if(k <= c1) return quick_select(l, x, k);
        else if(k <= c1 + c2) return p;
        else return quick_select(y, r, k - c1 - c2);
    }
}

int main()
{
    srand(time(0));

    scanf("%d%d", &n, &k);
    k++;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", quick_select(1, n, k));

    return 0;
}
