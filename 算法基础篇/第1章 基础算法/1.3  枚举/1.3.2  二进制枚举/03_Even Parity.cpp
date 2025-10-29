//# UVA11464 Even Parity
//
//## 题目描述
//
//给你一个 $n \times n$ 的 $01$ 矩阵（每个元素非 $0$ 即 $1$），你的任务是把尽量少的 $0$ 变成 $1$，使得原矩阵便为偶数矩阵（矩阵中每个元素的上、下、左、右的元素（如果存在的话）之和均为偶数）。
//
//## 输入格式
//
//输入的第一行为数据组数 $T$（$T \le 30$）。每组数据：第一行为正整数 $n$（$1 \le n \le 15$）；接下来的 $n$ 行每行包含 $n$ 个非 $0$ 即 $1$ 的整数，相邻整数间用一个空格隔开。
//
//## 输出格式
//
//对于每组数据，输出被改变的元素的最小个数。如果无解，输出 $-1$。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//3
//0 0 0
//0 0 0
//0 0 0
//3
//0 0 0
//1 0 0
//0 0 0
//3
//1 1 1
//1 1 1
//0 0 0
//```
//
//### 输出 #1
//
//```
//Case 1: 0
//Case 2: 3
//Case 3: -1
//```

#include <iostream>
#include <cstring>

using namespace std;

const int N = 20;

int n;
int a[N];//用二进制存储状态
int t[N];//备份

//判断x->y是否合法
//返回-1表示不合法
//其余的数表示合法，且表示0->1的次数
int calc(int x, int y)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) sum++;
        if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
    }

    return sum;
}

int solve()
{
    int ret = 0x3f3f3f3f;

    //枚举第一行的最终状态
    for(int st = 0; st < (1 << n); st++)
    {
        memcpy(t, a, sizeof a);

        int change = st;
        int cnt = 0;//统计0->1的次数
        bool flag = 1;

        for(int i = 1; i <= n; i++)
        {
            //先判断change是否合法
            int c = calc(t[i], change);
            if(c == -1)
            {
                flag = 0;
                break;
            }

            cnt += c;//累加次数
            //当前行的最终状态
            t[i] = change;
            //计算下一行的最终状态
            change = t[i - 1] ^ (t[i] << 1) ^ (t[i] >> 1);
            change &= (1 << n) - 1;
        }

        if(flag) ret = min(ret, cnt);
    }

    if(ret == 0x3f3f3f3f) return -1;
    else return ret;
}

int main()
{
    int T;
    cin >> T;
    for(int k = 1; k <= T; k++)
    {
        memset(a, 0, sizeof a);

        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                if(x) a[i] |= 1 << j;
            }

        }

        printf("Case %d: %d\n", k, solve());
    }

    return 0;
}
