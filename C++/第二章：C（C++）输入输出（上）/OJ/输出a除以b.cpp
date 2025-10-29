//链接：https://ac.nowcoder.com/acm/problem/21992
//来源：牛客网
//
//题目描述 
//
//输入两个整数a, b, 输出a除以b的值，保留三位小数
//输入描述:
//输入两个整数，在int范围内
//输出描述:
//输出一个浮点数，保留三位小数
//示例1
//输入
//复制
//5 2
//输出
//复制
//2.500


#include <cstdio>

using namespace std;

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%.3lf\n", a * 1.0 / b);
    
    return 0;
}
