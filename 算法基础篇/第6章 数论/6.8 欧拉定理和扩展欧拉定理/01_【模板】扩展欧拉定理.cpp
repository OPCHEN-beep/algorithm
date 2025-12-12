//# P5091 【模板】扩展欧拉定理
//
//## 题目背景
//
//出题人也想写有趣的题面，可惜并没有能力。
//
//## 题目描述
//
//给你三个正整数，$a,m,b$，你需要求：$a^b \bmod m$
//
//## 输入格式
//
//一行三个整数，$a,m,b$
//
//## 输出格式
//
//一个整数表示答案
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//2 7 4
//```
//
//### 输出 #1
//
//```
//2
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//998244353 12345 98765472103312450233333333333
//```
//
//### 输出 #2
//
//```
//5333
//```
//
//## 说明/提示
//
//注意输入格式，$a,m,b$ 依次代表的是底数、模数和次数   
//
//【样例 $1$ 解释】   
//$2^4 \bmod 7 = 2$     
//     
//【数据范围】  
//对于 $100\%$ 的数据，$1\le a \le 10^9$，$1\le b \le 10^{20000000}，1\le m \le 10^8$。

#include <iostream>

using namespace std;

typedef long long LL;

LL a, m;
string s;

//试除法求单个数的欧拉函数
LL get_phi(LL x)
{
    LL ret = x;
    for(int i = 2; i <= x / i; i++)
    {
        if(x % i == 0)
        {
            ret = ret / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ret = ret / x * (x - 1);

    return ret;
}

LL get_b(string& s, LL phi)
{
    LL t = 0;
    bool flag = false;
    for(auto ch : s)
    {
        t = t * 10 + ch - '0';
        if(t >= phi)
        {
            flag = true;
            t %= phi;
        }
    }
    if(flag) t += phi;

    return t;
}

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

int main()
{
    cin >> a >> m >> s;

    LL phi = get_phi(m);
    LL b = get_b(s, phi);

    cout << qpow(a, b, m) << endl;

    return 0;
}
