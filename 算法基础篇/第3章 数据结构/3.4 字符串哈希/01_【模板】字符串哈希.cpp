//# P3370 【模板】字符串哈希
//
//## 题目描述
//
//如题，给定 $N$ 个字符串（第 $i$ 个字符串长度为 $M_i$，字符串内包含数字、大小写字母，大小写敏感），请求出 $N$ 个字符串中共有多少个不同的字符串。
//
//
//**友情提醒：如果真的想好好练习哈希的话，请自觉。**
//
//## 输入格式
//
//第一行包含一个整数 $N$，为字符串的个数。
//
//接下来 $N$ 行每行包含一个字符串，为所提供的字符串。
//
//## 输出格式
//
//输出包含一行，包含一个整数，为不同的字符串个数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//abc
//aaaa
//abc
//abcc
//12345
//```
//
//### 输出 #1
//
//```
//4
//```
//
//## 说明/提示
//
//### 数据范围
//
//对于 $30\%$ 的数据：$N\leq 10$，$M_i≈6$，$M_{\max}\leq 15$。
//
//对于 $70\%$ 的数据：$N\leq 1000$，$M_i≈100$，$M_{\max}\leq 150$。
//
//对于 $100\%$ 的数据：$N\leq 10000$，$M_i≈1000$，$M_{\max}\leq 1500$。
//
//### 样例说明
//
//样例中第一个字符串 $\tt{abc}$ 和第三个字符串 $\tt{abc}$ 是一样的，所以所提供字符串的集合为 $\{\tt{aaaa},\tt{abc},\tt{abcc},\tt{12345}\}$，故共计 $4$ 个不同的字符串。
//
//### 拓展阅读
//
//以下的一些试题从不同层面体现出了字符串哈希算法的正确性分析。
//
//- [P12197 Hash Killer I](https://www.luogu.com.cn/problem/P12197)
//- [P12198 Hash Killer II](https://www.luogu.com.cn/problem/P12198)
//- [P12199 （目前无解）Hash Killer III](https://www.luogu.com.cn/problem/P12199)
//- [P12200 Hash Killer Extra](https://www.luogu.com.cn/problem/P12200)
//- [P12201 Hash Killer Phantasm](https://www.luogu.com.cn/problem/P12201)
//- [P7350 「MCOI-04」Dream and Strings](https://www.luogu.com.cn/problem/P7350)

#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e4 + 10, P = 131;

int n;
ULL a[N];

//字符串哈希
ULL get_hash(string& s)
{
    ULL ret = 0;
    for(int i = 1; i <= s.size(); i++)
    {
        ret = ret * P + s[i - 1];
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a[i] = get_hash(s);
    }

    int ret = 1;
    sort(a + 1, a + 1 + n);
    for(int i = 2; i <= n; i++)
    {
        if(a[i] != a[i - 1]) ret++;
    }

    cout << ret << endl;

    return 0;
}
