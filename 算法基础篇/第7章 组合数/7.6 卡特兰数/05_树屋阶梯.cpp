//# P2532 [AHOI2012] 树屋阶梯
//
//## 题目描述
//
//![](https://cdn.luogu.com.cn/upload/pic/1630.png) 
//
// ![](https://cdn.luogu.com.cn/upload/pic/1631.png)
//
//## 输入格式
//
//一个正整数 $N$，表示阶梯的高度。
//
//## 输出格式
//
//一个正整数，表示搭建方法的个数。**注**：搭建方法的个数可能很大。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//```
//
//### 输出 #1
//
//```
//5
//```
//
//## 说明/提示
//
//- 对于 $40\%$ 的数据，满足 $1\le N\le 20$。
//- 对于 $80\%$ 的数据，满足 $1\le N\le 300$。
//- 对于 $100\%$ 的数据，满足 $1\le N\le 500$。

#include <iostream>

using namespace std;

const int N = 510;

int n;
int f[N][N];

void add(int c[], int b[])
{
    for(int i = 0; i < N - 1; i++)
    {
        c[i] += b[i];
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
}

int main()
{
    cin >> n;

    f[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
        {
            add(f[j], f[j - 1]);
        }

    int p = N - 1;
    while(f[n][p] == 0) p--;
    while(p >= 0) cout << f[n][p--];

    return 0;
}
