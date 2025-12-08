//小红的 gcd
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC275615
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//给两个正整数
//a
//,
//b
//a,b，输出他们的最大公约数 
//gcd
//?
//(
//a
//,
//b
//)
//gcd(a,b)。
//输入描述:
//第一行一个正整数 
//a
//a。
//第二行一个正整数 
//b
//b。
//l
//e
//n
//len表示
//a
//a的十进制位数，
//1
//≤
//l
//e
//n
//≤
//1
//0
//6
//1≤len≤10 
//6
// 。
//1
//≤
//b
//≤
//1
//0
//9
//1≤b≤10 
//9
// 。
//输出描述:
//输出一个整数，表示
//gcd
//?
//(
//a
//,
//b
//)
//gcd(a,b)。
//示例1
//输入
//复制
//12345678
//12
//输出
//复制
//6

#include <iostream>

using namespace std;

string a;
int b;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int calc()
{
    long long t = 0;
    for(auto ch : a)
    {
        t = t * 10 + ch - '0';
        t %= b;
    }
    return t;
}

int main()
{
    cin >> a >> b;
    
    cout << gcd(b, calc()) << endl;
    
    return 0;
}
