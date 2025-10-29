//# P10446 64位整数乘法
//
//## 题目描述
//
//求 $a$ 乘 $b$ 对 $p$ 取模的值。
//
//## 输入格式
//
//第一行输入整数 $a$，第二行输入整数 $b$，第三行输入整数 $p$。
//
//## 输出格式
//
//输出一个整数，表示 `a*b mod p` 的值。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//4
//5
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 说明/提示
//
//$1 \le a,b,p \le 10^{18}$

#include <iostream>
using namespace std;

typedef long long LL;

//加法比乘法快，并且能防止溢出
LL qmul(LL a, LL b, LL p)
{
    LL sum = 0;
    while(b)  //枚举b的二进制位
    {
        if(b & 1) sum = (sum + a) % p;
        a = (a + a) % p;  //计算下一个权值
        b >>= 1;
    }

    return sum % p;
}

int main()
{
    LL a, b, p;
    cin >> a >> b >> p;
    cout << qmul(a % p, b, p) << endl;

    return 0;
}
