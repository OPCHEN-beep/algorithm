//# B2110 找第一个只出现一次的字符
//
//## 题目描述
//
//给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出 `no`。
//
//## 输入格式
//
//一个字符串，长度小于 $1100$。
//
//## 输出格式
//
//输出第一个仅出现一次的字符，若没有则输出 `no`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//abcabd
//```
//
//### 输出 #1
//
//```
//c
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//aabbcc
//```
//
//### 输出 #2
//
//```
//no
//```

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1110;
char str[N];
int nums[128];

int main()
{
    cin >> str;
    int i = 0;
    while(str[i])
    {
        nums[str[i]]++;
        i++;
    }
    i = 0;
    int flag = 0;
    while(str[i])
    {
        if(nums[str[i]] == 1)
        {
            cout << str[i] << endl;
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
    {
        cout << "no" << endl;
    }

    return 0;
}
