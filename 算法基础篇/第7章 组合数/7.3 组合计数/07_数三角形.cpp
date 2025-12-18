//# P3166 [CQOI2014] 数三角形
//
//## 题目描述
//
//给定一个 $N\times M$ 的网格，请计算三点都在格点上的三角形共有多少个。注意三角形的三点不能共线。
//
//## 输入格式
//
//输入一行，包含两个空格分隔的正整数 $M$ 和 $N$。
//
//## 输出格式
//
//输出一个正整数，为所求三角形数量。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 2
//```
//
//### 输出 #1
//
//```
//76
//```
//
//## 说明/提示
//
//#### 数据规模与约定
//
//对于全部的测试点，保证 $1\le N,M\le1000$。

#include <iostream>

using namespace std;

typedef long long LL;

LL n, m;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cin >> n >> m;
    n++, m++;

    LL t = n * m;
    LL ret = t * (t - 1) * (t - 2) / 6;
    ret -= n * m * (m - 1) * (m - 2) / 6;
    ret -= m * n * (n - 1) * (n - 2) / 6;

    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++)
            ret -= 2 * ((n - j) * (m - i) * (gcd(i, j) - 1));

    cout << ret << endl;

    return 0;
}
