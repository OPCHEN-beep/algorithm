//# B2079 求出 e 的值
//
//## 题目描述
//
//利用公式 $e=1+1/1!+1/2!+1/3!+ \cdots +1/n!$，求 $e$ 的值，要求保留小数点后 $10$ 位。
//
//## 输入格式
//
//输入只有一行，该行包含一个整数 $n$，表示计算 $e$ 时累加到 $1/n!$。
//
//## 输出格式
//
//输出只有一行，该行包含计算出来的 $e$ 的值，要求打印小数点后 $10$ 位。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10
//```
//
//### 输出 #1
//
//```
//2.7182818011
//```
//
//## 说明/提示
//
//$2 \le n \le 15$。

#include <iostream>
#include <cstdio>
using namespace std;


//错误答案: 
//int main()
//{
//    int n;
//    cin >> n;
//    int i = 1; 
//    double e = 1.0;
//    long long cnt = 1;
//    
//    while(i <= n)
//    {
//        for(int j = 1; j <= i; j++)
//        {
//            cnt *= j;
//        }
//        e += 1.0 / cnt;
//        i++;
//    }
//    printf("%.10lf\n", e);
//
//    return 0;
//}


//正确答案：
int main()
{
    int n;
    double sum = 1;
    cin >> n;
    //循环n次
    for(int i = 1; i <= n; i++)
    {
        //求i的阶乘
        long long r = 1;
        for(int j = 1; j <= i; j++)
        {
            r *= j;
        }
        sum += 1.0 / r;
    }
    printf("%.10lf\n", sum);

    return 0;
}
