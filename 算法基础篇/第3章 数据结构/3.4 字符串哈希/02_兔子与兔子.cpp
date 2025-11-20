//# P10468 兔子与兔子
//
//## 题目描述
//
//很久很久以前，森林里住着一群兔子。
//
//有一天，兔子们想要研究自己的 DNA 序列。
//
//我们首先选取一个好长好长的 DNA 序列（小兔子是外星生物，DNA 序列可能包含 $26$ 个小写英文字母）。
//
//然后我们每次选择两个区间，询问如果用两个区间里的 DNA 序列分别生产出来两只兔子，这两个兔子是否一模一样。
//
//注意两个兔子一模一样只可能是他们的 DNA 序列一模一样。
//
//## 输入格式
//
//第一行输入一个 DNA 字符串 $S$。
//
//第二行一个数字 $m$，表示 $m$ 次询问。
//
//接下来 $m$ 行，每行四个数字 $l_1, r_1, l_2, r_2$，分别表示此次询问的两个区间，注意字符串的位置从 $1$ 开始编号。
//
//## 输出格式
//
//对于每次询问，输出一行表示结果。
//
//如果两只兔子完全相同输出 `Yes`，否则输出 `No`（注意大小写）。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//aabbaabb
//3
//1 3 5 7
//1 3 6 8
//1 2 1 2
//```
//
//### 输出 #1
//
//```
//Yes
//No
//Yes
//```
//
//## 说明/提示
//
//数据保证，$1 \le |S|,m \le 10^6$。其中，$|S|$ 为字符串 $S$ 的长度。

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e6 + 10, P = 13331;

int n;
string s;
ULL f[N];  //前缀哈希数组
ULL p[N];  //p的i次方

void init_bash()
{
    p[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }
}

ULL get_hash(int l, int r)
{
    return f[r] - f[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> s;
    n = s.size();
    s = " " + s;

    init_bash();

    int m;
    cin >> m;

    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        ULL x = get_hash(l1, r1), y = get_hash(l2, r2);

        if(x == y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
