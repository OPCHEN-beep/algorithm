//约数个数的和
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC14682
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//给个n，求1到n的所有数的约数个数的和~
//
//输入描述:
//第一行一个正整数n
//输出描述:
//输出一个整数，表示答案
//示例1
//输入
//复制
//3
//输出
//复制
//5
//说明
//样例解释：
//1有1个约数1
//2有2个约数1,2
//3有2个约数1,3
//备注:
//n <= 100000000

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    
    for(int i = 1; i <= n / 2; i++) sum += n / i;
    sum += n - n / 2;
    
    cout << sum << endl;
    
    return 0;
}
