//大水题
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC15079
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//给出一个数n，求1到n中，有多少个数不是2 5 11 13的倍数。
//输入描述:
//本题有多组输入
//每行一个数n，1<=n<=10^18.
//输出描述:
//每行输出输出不是2 5 11 13的倍数的数共有多少。
//示例1
//输入
//复制
//15
//输出
//复制
//4
//说明
//1 3 7 9

#include <iostream>

using namespace std;

typedef long long LL;

LL n;

int main()
{
    while(cin >> n)
    {
        LL ret = n;
        ret -= n / 2 + n / 5 + n / 11 + n / 13;
        ret += n / 10 + n / 22 + n / 26 + n / 55 + n / 65 + n / 143;
        ret -= n / 110 + n / 130 + n / 286 + n / 715;
        ret += n / 1430;
        cout << ret << endl;
    }
    
    return 0;
}
