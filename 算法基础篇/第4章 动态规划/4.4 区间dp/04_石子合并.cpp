//# P1880 [NOI1995] 石子合并
//
//## 题目描述
//
//在一个圆形操场的四周摆放 $N$ 堆石子，现要将石子有次序地合并成一堆，规定每次只能选相邻的 $2$ 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
//
//试设计出一个算法,计算出将 $N$ 堆石子合并成 $1$ 堆的最小得分和最大得分。
//
//## 输入格式
//
//数据的第 $1$ 行是正整数 $N$，表示有 $N$ 堆石子。
//
//第 $2$ 行有 $N$ 个整数，第 $i$ 个整数 $a_i$ 表示第 $i$ 堆石子的个数。
//
//## 输出格式
//
//输出共 $2$ 行，第 $1$ 行为最小得分，第 $2$ 行为最大得分。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4
//4 5 9 4
//```
//
//### 输出 #1
//
//```
//43
//54
//```
//
//## 说明/提示
//
//$1\leq N\leq 100$，$0\leq a_i\leq 20$。

#include <iostream>
#include <cstring>

using namespace std;

const int N = 210;

int n, m;
int s[N];
int f[N][N];  //最小得分
int g[N][N];  //最大得分

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        //倍增
        s[i + n] = s[i];
    }
    m = n + n;

    //前缀和
    for(int i = 1; i <= m; i++)
    {
        s[i] += s[i - 1];
    }

    //初始化
    memset(f, 0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);
    for(int i = 1; i <= m; i++)
    {
        f[i][i] = g[i][i] = 0;
    }
    for(int len = 1; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= m; i++)
        {
            int j = i + len - 1;
            int t = s[j] - s[i - 1];

            //枚举分割点
            for(int k = i; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + t);
                g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j] + t);
            }
        }
    }

    //更新结果
    int ret1 = 0x3f3f3f3f, ret2 = -0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        ret1 = min(ret1, f[i][i + n - 1]);
        ret2 = max(ret2, g[i][i + n - 1]);
    }

    cout << ret1 << endl << ret2 << endl;

    return 0;
}
