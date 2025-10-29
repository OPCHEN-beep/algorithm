#include <iostream>

using namespace std;

//# B2093 查找特定的值
//
//## 题目描述
//
//在一个序列（下标从 $0$ 开始）中查找一个给定的值，输出第一次出现的位置。
//
//## 输入格式
//
//第一行包含一个正整数 $n$，表示序列中元素个数。$1 \le n \le 10000$。
//
//第二行包含 $n$ 个整数，依次给出序列的每个元素，相邻两个整数之间用单个空格隔开。元素的绝对值不超过 $10000$。
//
//第三行包含一个整数 $x$，为需要查找的特定值。$x$ 的绝对值不超过 $10000$。
//
//## 输出格式
//
//若序列中存在 $x$，输出 $x$ 第一次出现的下标；  否则输出 `-1`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//2 3 6 7 3
//3
//```
//
//### 输出 #1
//
//```
//1
//```

#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10010;
int arr[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k = 0;
    cin >> k;
    int i = 0;
    for(i = 0; i< n; i++)
    {
        if(arr[i] == k)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}
