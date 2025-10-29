//# B2139 区间内的真素数
//
//## 题目描述
//
//找出正整数 $M$ 和 $N$ 之间（$N$ 不小于 $M$）的所有真素数。
//
//真素数的定义：如果一个正整数 $P$ 为素数，且其反序也为素数，那么 $P$ 就为真素数。
//
//例如，$11$，$13$ 均为真素数，因为 $11$ 的反序还是为 $11$，$13$ 的反序为 $31$ 也为素数。
//
//## 输入格式
//
//输入两个数 $M$ 和 $N$，空格间隔。
//
//## 输出格式
//
//按从小到大输出 $M$ 和 $N$ 之间（包括 $M$ 和 $N$）的真素数，逗号间隔。如果之间没有真素数，则输出 `No`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10 35
//```
//
//### 输出 #1
//
//```
//11,13,17,31
//```
//
//## 说明/提示
//
//$1 \le M \le N \le 100000$


#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool IsPrime(int n)
{
    if(n <= 1)
        return false;
    for(int j = 2; j <=sqrt(n); j++)
    {
        if(n % j == 0)
            return false;
    }
    return true;
}

int ReverseInt(int k)
{
    
    int ret = 0;
    while(k)
    {
        ret  = ret * 10 + k % 10;
        k /= 10;
    }
    return ret;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int flag = 0;
    int  i = 0;
    for( i = m; i <= n; i++)
    {
        int i2 = ReverseInt(i);
        if(IsPrime(i) && IsPrime(i2))
        {
            if(flag)
                cout << ",";
            cout << i;
            flag++;
        }
    }
    if(flag == 0)
        cout << "No" << endl;

    return 0;
}
