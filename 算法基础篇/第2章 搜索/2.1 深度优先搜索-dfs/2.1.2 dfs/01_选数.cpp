//# P1036 [NOIP 2002 普及组] 选数
//
//## 题目描述
//
//已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$ 个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：
//
//$3+7+12=22$
//
//$3+7+19=29$
//
//$7+12+19=38$
//
//$3+12+19=34$
//
//现在，要求你计算出和为素数共有多少种。
//
//例如上例，只有一种的和为素数：$3+7+19=29$。
//
//## 输入格式
//
//第一行两个空格隔开的整数 $n,k$（$1 \le n \le 20$，$k<n$）。
//
//第二行 $n$ 个整数，分别为 $x_1,x_2,\cdots,x_n$（$1 \le x_i \le 5\times 10^6$）。
//
//## 输出格式
//
//输出一个整数，表示种类数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4 3
//3 7 12 19
//```
//
//### 输出 #1
//
//```
//1
//```
//
//## 说明/提示
//
//**【题目来源】**
//
//NOIP 2002 普及组第二题

#include <iostream>

using namespace std;

const int N = 1e8 + 10;

int n, k, x[N];
int p[N], cnt;
bool st[N];

int ret;
int path;  //记录路径中所选择的数的和

void get_prime()
{
    int n = 1e8;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) p[++cnt] = i;

        //枚举所有的质数
        for(int j = 1; 1ll * i * p[j] <= n; j++)
        {
            st[i * p[j]] = true;
            if(i % p[j] == 0) break;
        }
    }
}

void dfs(int pos, int begin)
{
    if(pos > k)
    {
        if(!st[path]) ret++;
        return;
    }

    for(int i = begin; i <= n; i++)
    {
        path += x[i];
        dfs(pos + 1, i + 1);
        path -= x[i];  //恢复现场
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    get_prime();

    dfs(1, 1);

    cout << ret << endl;

    return 0;
}
