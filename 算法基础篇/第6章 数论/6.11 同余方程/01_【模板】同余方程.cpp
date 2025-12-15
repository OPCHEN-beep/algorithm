//【模板】同余方程
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC229005
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//求关于
// 
//x
// x 的同余方程
//a
//x
//≡
//1
//(
//m
//o
//d
//b
//)
//ax≡1(modb)的最小正整数解，若无解，输出"-1"。
//输入描述:
//第一行一个正整数
// 
//T
// T，表示
// 
//T
// T组数据。
//接下来
// 
//T
// T行，每行两个正整数
// 
//a
//,
//b
//(
//2
//≤
//a
//,
//b
//≤
//2
//?
//1
//0
//9
//)
// a,b(2≤a,b≤2?10 
//9
// )。
//输出描述:
//对于每组数据，输出同余方程的最小正整数解，若无解，输出"-1"（没有引号）。
//示例1
//输入
//复制
//2
//3 10
//2 4
//输出
//复制
//7
//-1

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
    
    LL x1, y1;
    LL d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        LL a, b;
        cin >> a >> b;
        LL x, y , d;
        d = exgcd(a, b, x, y);
        
        if(d == 1)
        {
            x = (x % b + b) % b;
            cout << x << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
