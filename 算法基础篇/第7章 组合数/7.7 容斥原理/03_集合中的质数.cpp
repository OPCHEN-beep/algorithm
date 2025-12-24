//集合中的质数
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC14686
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//给出一个集合和一个数m。
//
//集合里面有n个质数。
//
//请你求出从 1 到 m 的所有数中，至少能被集合中的一个数整除的数的个数。
//
//输入描述:
//第一行两个正整数 n 和 m 。
//第二行n个正整数，分别为集合中的质数。
//输出描述:
//输出一个整数，表示符合要求的正整数的个数。
//示例1
//输入
//复制
//3 37
//5 7 13
//输出
//复制
//13
//备注:
//对于100%的数据，有n<=20，m为有符号64位正整数，集合内质数<=1000000000

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 30;

LL n, m;
LL p[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> p[i];
    
    LL ret = 0;
    for(int st = 1; st < (1 << n); st++)
    {
        LL t = m, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if((st >> i) & 1)
            {
                cnt++;
                t /= p[i];
            }
        }
        
        if(cnt % 2 == 0) ret -= t;
        else ret += t;
    }
    cout << ret << endl;
    
    return 0;
}
