//# P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪
//
//## 题目描述
//
//自从曹冲搞定了大象以后，曹操就开始捉摸让儿子干些事业，于是派他到中原养猪场养猪，可是曹冲满不高兴，于是在工作中马马虎虎，有一次曹操想知道母猪的数量，于是曹冲想狠狠耍曹操一把。举个例子，假如有 $16$ 头母猪，如果建了 $3$ 个猪圈，剩下 $1$ 头猪就没有地方安家了。如果建造了 $5$ 个猪圈，但是仍然有 $1$ 头猪没有地方去，然后如果建造了 $7$ 个猪圈，还有 $2$ 头没有地方去。你作为曹总的私人秘书理所当然要将准确的猪数报给曹总，你该怎么办？
//
//## 输入格式
//
//第一行包含一个整数 $n$ —— 建立猪圈的次数，接下来 $n$ 行，每行两个整数 $a_i, b_i$，表示建立了 $a_i$ 个猪圈，有 $b_i$ 头猪没有去处。你可以假定 $a_1 \sim a_n$ 互质。
//
//## 输出格式
//
//输出包含一个正整数，即为曹冲至少养母猪的数目。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//3 1
//5 1
//7 2
//```
//
//### 输出 #1
//
//```
//16
//```
//
//## 说明/提示
//
//$1 \leq n\le10$，$0 \leq b_i\lt a_i\le100000$，$1 \leq \prod a_i \leq 10^{18}$

#include <iostream>

using namespace std;

typedef long long LL;

const int N = 15;

int n;
LL r[N], m[N];

LL qmul(LL a, LL b, LL p)
{
    LL ret = 0;
    while(b)
    {
        if(b & 1) ret = (ret + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return ret;
}

void exgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return;
    }

    LL x1, y1;
    exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
}

LL crt()
{
    LL M = 1;
    for(int i = 1; i <= n; i++) M *= m[i];

    LL ret = 0;
    for(int i = 1; i <= n; i++)
    {
        LL c = M / m[i];
        LL x, y;
        exgcd(c, m[i], x, y);
        x = (x % m[i] + m[i]) % m[i];

        ret = (ret + qmul(qmul(c, x, M), r[i], M)) % M;
    }

    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> m[i] >> r[i];

    cout << crt() << endl;

    return 0;
}
