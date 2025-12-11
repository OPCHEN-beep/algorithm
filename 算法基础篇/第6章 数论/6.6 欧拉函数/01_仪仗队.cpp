//# P2158 [SDOI2008] 仪仗队
//
//## 题目描述
//
//作为体育委员，C 君负责这次运动会仪仗队的训练。仪仗队是由学生组成的 $N \times N$ 的方阵，为了保证队伍在行进中整齐划一，C 君会跟在仪仗队的左后方，根据其视线所及的学生人数来判断队伍是否整齐（如下图）。
//
//![](https://cdn.luogu.com.cn/upload/pic/1149.png)
//
//现在，C 君希望你告诉他队伍整齐时能看到的学生人数。
//
//## 输入格式
//
//一行，一个正整数 $N$。
//
//## 输出格式
//
//输出一行一个数，即 C 君应看到的学生人数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//4
//```
//
//### 输出 #1
//
//```
//9
//```
//
//## 说明/提示
//
//对于 $100 \%$ 的数据，$1 \le N \le 40000$。

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 40010;

int n;
bool st[N];
int p[N], cnt;
int phi[N];

void get_phi()
{
    phi[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            phi[i] = i - 1;
            p[++cnt] = i;
        }

        for(int j = 1; 1ll * i * p[j] <= n; j++)
        {
            int x = i * p[j];
            st[x] = true;

            if(i % p[j] == 0)
            {
                phi[x] = phi[i] * p[j];
                break;
            }
            else
            {
                phi[x] = phi[i] * (p[j] - 1);
            }
        }
    }
}

int main()
{
    cin >> n;

    get_phi();

    LL sum = 0;
    for(int i = 1; i < n; i++)
    {
        sum += phi[i];
    }

    if(n == 1) cout << 0 << endl;
    else cout << sum * 2 + 1 << endl;

    return 0;
}
