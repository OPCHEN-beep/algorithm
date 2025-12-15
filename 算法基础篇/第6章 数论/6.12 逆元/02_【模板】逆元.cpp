//【模板】逆元
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC226824
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//求x模p意义下的逆元，若不存在，请输出-1.
//
//逆元的定义：
//x模p意义下的逆元，指的是求y，使得
//x
//?
//y
//≡
//1
// 
//m
//o
//d
// 
//p
//x?y≡1 mod p。
//输入描述:
//第一行一个整数T，表示T个测试用例。(1 <= T <= 10000)
//接下来T行，每行2个整数x, p（2 <= x < p <= 10^9）
//输出描述:
//输出每组测试用例的答案
//示例1
//输入
//复制
//2
//4 8
//2 1000000007
//输出
//复制
//-1
//500000004
//说明
//2*500000004 = 1000000008
//
//1000000008 在模1000000007意义下与1同余。

#include <iostream>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    
    LL x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a, b;
        cin >> a >> b;
        LL x, y, d;
        d = exgcd(a, b, x, y);
        
        if(d != 1) cout << -1 << endl;
        else cout << (x % b + b) % b << endl;
    }
    
    return 0;
}
