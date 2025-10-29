//# P1104 生日
//
//## 题目描述
//
//cjf 君想调查学校 OI 组每个同学的生日，并按照年龄从大到小的顺序排序。但 cjf 君最近作业很多，没有时间，所以请你帮她排序。
//
//## 输入格式
//
//输入共有 $n + 1$ 行，
//
//第 $1$ 行为 OI 组总人数 $n$；
//
//第 $2$ 行至第 $n+1$ 行分别是每人的姓名 $s$、出生年 $y$、月 $m$、日 $d$。
//
//## 输出格式
//
//输出共有 $n$ 行，
//
//即 $n$ 个生日从大到小同学的姓名。（如果有两个同学生日相同，输入靠后的同学先输出）
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//Yangchu 1992 4 23
//Qiujingya 1993 10 13
//Luowen 1991 8 1
//```
//
//### 输出 #1
//
//```
//Luowen
//Yangchu
//Qiujingya
//```
//
//## 说明/提示
//
//数据保证，$1<n<100$，$1\leq |s|<20$。保证年月日实际存在，且年份 $\in [1960,2020]$。

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 110;

struct S
{
    string s;
    int y;
    int m;
    int d;
    int id;
}arr[N];

bool cmp(struct S s1, struct S s2)
{
    if(s1.y != s2.y)
        return s1.y < s2.y;
    else if(s1.m != s2.m)
        return s1.m < s2.m;
    else if(s1.d != s2.d)
        return s1.d < s2.d;
    else
        return s1.id > s2.id;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i].s >> arr[i].y >> arr[i].m >> arr[i].d;
        arr[i].id = i;
    }

    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i].s << endl;
    }
    
    return 0;
}
