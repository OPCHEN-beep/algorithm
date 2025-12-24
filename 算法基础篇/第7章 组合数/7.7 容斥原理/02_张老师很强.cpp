//张老师很强
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC24517
//时间限制：C/C++/Rust/Pascal 3秒，其他语言6秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//张老师最近在看《最强大脑》节目，然后张老师突然发觉自己原来很强！张老师对一个很大的正整数n，他可以一秒钟找到n以内有几个数是a或者b的倍数。突然发现自己这么强，张老师已经感觉自己已经可以上天了，计算机都没办法跟他肩并肩。所以请同学们帮忙让张老师清醒一点，告诉他计算机也可以轻松做到这件事情。
//输入描述:
//第一行一个整数t（1<=t<=105）表示有t组数据
//接下来t行，每行3个整数n,a,b（1<=a,b,n<=2×109）
//输出描述:
//对于每一组数据输出一行，每行一个整数表示n以内a或者b倍数的个数
//示例1
//输入
//复制
//3
//10 2 3
//10 3 4
//10 4 5
//输出
//复制
//7
//5
//4

#include <iostream>

using namespace std;

typedef long long LL;

LL n, a, b;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> a >> b;
        
        cout << (n / a + n / b - n / lcm(a, b)) << endl;
    }
    
    return 0;
}
