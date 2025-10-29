//# B2128 素数个数
//
//## 题目描述
//
//编程求 $2$ ～ $n(n$ 为大于等于 $2$ 的正整数）中有多少个素数。
//
//## 输入格式
//
//输入 $n(2 \le n \le 50000)$。
//
//## 输出格式
//
//素数个数。
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
//4
//```

#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(int n)
{
    int j = 0;
    if(n < 2)
        return false;
    for(j = 2; j <= sqrt(n); j++)
    {
        if(n % j == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 0;
    int cnt = 0;
    cin >> n;
    int i = 0;
    for(i = 2; i <= n; i++)
    {
        if(IsPrime(i))
            cnt++;
    }
    cout << cnt << endl;

    return 0;
}
