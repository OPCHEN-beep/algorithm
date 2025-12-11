//序列求和
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC15950
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 128 M，其他语言256 M
//64bit IO Format: %lld
//题目描述 
//定义S(n) = 12 + 22 + … + n2，输出S(n) % 1000000007。
//
//注意：1 < n < 1e18。
//输入描述:
//多组输入，输入直到遇到EOF为止；
//
//第一行输入一个正整数n。
//输出描述:
//输出S(n) % 1000000007的结果。
//示例1
//输入
//复制
//1
//2
//1000
//输出
//复制
//1
//5
//333833500

#include <iostream>

using namespace std;

typedef long long LL;

const int p = 1e9 + 7;

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
    LL n;
    while(cin >> n)
    {
        LL a = n % p, b = (n + 1) % p, c = (n * 2 + 1) % p, d = qpow(6, p - 2, p);
        cout << (((a * b) % p * c) % p * d) % p << endl;
    }
    
    return 0;
}
