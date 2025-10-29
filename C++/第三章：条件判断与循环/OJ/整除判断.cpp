//链接：https://ac.nowcoder.com/acm/contest/19304/D
//来源：牛客网
//
//题目描述 
//乎乎学会了除法，他想知道整数m能否被整数n整除。
//输入描述:
//输入仅一行，有两个整数（范围1 ~231-1），第一个为m，第二个为n。
//输出描述:
//输出仅一行，m 能被 n 整除输出 YES，否则输出 NO。
//示例1
//输入
//复制
//36 6
//输出
//复制
//YES

#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
    size_t m, n;
    scanf("%d %d", &m, &n);
    if(m % n == 0)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
// 64 位输出请用 printf("%lld")

