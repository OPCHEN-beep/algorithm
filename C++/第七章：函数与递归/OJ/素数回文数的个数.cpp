//# B2136 素数回文数的个数
//
//## 题目描述
//
//求 $11$ 到 $n$ 之间（包括 $n$），既是素数又是回文数的整数有多少个。
//
//## 输入格式
//
//一个大于 $11$ 小于 $10000$ 的整数 $n$。
//
//## 输出格式
//
//$11$ 到 $n$ 之间的素数回文数个数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//23
//```
//
//### 输出 #1
//
//```
//1
//```
//
//## 说明/提示
//
//回文数指左右对称的数，如：$11$，$12121$。

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

bool IsHuiwen(int n)
{
    int tmp = n;
    int ret = 0;
    while(tmp)
    {
        ret  =ret * 10 + tmp % 10;
        tmp /= 10;
    }
    if(ret == n)
        return true;
    else
        return false;
}

int main()
{
    int n = 0;
    int cnt = 0;
    cin >> n;
    for(int i = 11; i <= n; i++)
    {
        if(IsPrime(i) && IsHuiwen(i))
        {
            cnt++;
        }
 
    }
    cout << cnt << endl;
    return 0;
}
