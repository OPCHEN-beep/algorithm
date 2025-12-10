//# P2043 质因子分解
//
//## 题目描述
//
//对 $N!$ 进行质因子分解。
//
//## 输入格式
//
//输入数据仅有一行包含一个正整数 $N$，$N \leq 10000$。
//
//## 输出格式
//
//输出数据包含若干行，每行两个正整数 $p,a$，中间用一个空格隔开。表示 $N!$ 包含 $a$ 个质因子 $p$，要求按 $p$ 的值从小到大输出。
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
//2 8
//3 4
//5 2
//7 1
//```
//
//## 说明/提示
//
//$10! = 3628800 = (2^8) \times (3^4) \times (5^2) \times 7$。

#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int n;
int c[N];

//试除法分解质因数
void deprime(int x)
{
    for(int i = 2; i <= x / i; i++)
    {
        int cnt = 0;
        while(x % i == 0)
        {
            cnt++;
            x /= i;
        }
        c[i] += cnt;
    }

    //注意判断最后一个数
    if(x > 1) c[x]++;
}

int main()
{
    cin >> n;
    for(int i =2; i <= n; i++)
    {
        deprime(i);
    }

    for(int i = 2; i <= n; i++)
    {
        if(c[i])
        {
            cout << i << " " << c[i] << endl;
        }
    }

    return 0;
}
