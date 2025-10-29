//# B2085 第 n 小的质数
//
//## 题目描述
//
//输入一个正整数 $n$，求正整数范围中第 $n$ 小的质数。
//
//## 输入格式
//
//一个不超过 $30000$ 的正整数 $n$。
//
//## 输出格式
//
//第 $n$ 小的质数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10
//```
//
//### 输出 #1
//
//```
//29
//```

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i =2;
    int cnt = 0;
    while(1)
    {
        int flag =1 ;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cnt++;
        }
        if(cnt == n)
            break;
        i++;
    }
    cout << i << endl;

    return 0;
}
