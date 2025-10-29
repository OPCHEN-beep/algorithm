//# P1226 【模板】快速幂
//
//## 题目描述
//
//给你三个整数 $a,b,p$，求 $a^b \bmod p$。
//
//## 输入格式
//
//输入只有一行三个整数，分别代表 $a,b,p$。
//
//## 输出格式
//
//输出一行一个字符串 `a^b mod p=s`，其中 $a,b,p$ 分别为题目给定的值， $s$ 为运算结果。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 10 9
//```
//
//### 输出 #1
//
//```
//2^10 mod 9=7
//```
//
//## 说明/提示
//
//**样例解释**
//
//$2^{10} = 1024$，$1024 \bmod 9 = 7$。
//
//**数据规模与约定**
//
//对于 $100\%$ 的数据，保证 $0\le a,b < 2^{31}$，$a+b>0$，$2 \leq p \lt 2^{31}$。

#include <iostream>
using namespace std;

typedef long long LL;

//a^b % p的值
LL quickpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1)ret = ret * a % p;
        a = a * a % p;
        b >>= 1;  //提取b的二进制位
    }
    return ret;
}

int main()
{
    LL a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, quickpow(a, b, p));

    return 0;                                            
}
