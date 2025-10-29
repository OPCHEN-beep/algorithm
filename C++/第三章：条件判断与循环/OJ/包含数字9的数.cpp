//描述
//今年是2019年，KiKi想知道1~2019中有多少个包含数字9的数。包含数字的数是指有某一位是“9”的数，例如“2019”、“199”等。
//
//
//
//   
//
//输入描述：
//无
//输出描述：
//一行，一个整数，表示1~2019中共有多少个数包含数字9。


#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    int cnt = 0;;
    for(int i = 9; i <= 2019; i++)
    {
        n = i;
        while(n)
        {
            if(n % 10 == 9)
            {
                cnt++;
                break;
            }
            n /= 10;
        }
    }
    printf("%d\n", cnt);
}
// 64 位输出请用 printf("%lld")
