//约数之和
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC22196
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//求自然数N的所有约数之和。
//输入描述:
//输入一行，包含一个正整数n，范围在10000以内
//输出描述:
//输出一行，包含一个整数.
//示例1
//输入
//复制
//10
//输出
//复制
//18

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    
    for(int i = 1; i <= n / i; i++)
    {
        if(n % i == 0)
        {
            sum += i;
            if(i != n / i) sum += n / i;
        }
    }
    
    cout << sum << endl;

    return 0;
}
