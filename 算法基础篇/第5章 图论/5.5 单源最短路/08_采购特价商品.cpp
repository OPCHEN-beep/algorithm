//# P1744 采购特价商品
//
//## 题目背景
//
//《爱与愁的故事第三弹·shopping》第一章。
//
//## 题目描述
//
//中山路店山店海，成了购物狂爱与愁大神的“不归之路”。中山路上有 $n$（$n \leq 100$）家店，每家店的坐标均在 $-10000$ 至 $10000$ 之间。其中的 $m$ 家店之间有通路。若有通路，则表示可以从一家店走到另一家店，通路的距离为两点间的直线距离。现在爱与愁大神要找出从一家店到另一家店之间的最短距离。你能帮爱与愁大神算出吗？
//
//## 输入格式
//
//共 $n+m+3$ 行：
//
//第一行：整数 $n$。 
//
//接下来 $n$ 行：每行两个整数 $x$ 和 $y$，描述了一家店的坐标。 
//
//接下来一行：整数 $m$。 
//
//接下来 $m$ 行：每行描述一条通路，由两个整数 $i$ 和 $j$ 组成，表示第 $i$ 家店和第 $j$ 家店之间有通路。
//
//接下来一行：两个整数 $s$ 和 $t$，分别表示原点和目标店。
//
//## 输出格式
//
//仅一行：一个实数（保留两位小数），表示从 $s$ 到 $t$ 的最短路径长度。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//0 0
//2 0
//2 2
//0 2
//3 1
//5
//1 2
//1 3
//1 4
//2 5
//3 5
//1 5
//```
//
//### 输出 #1
//
//```
//3.41
//```
//
//## 说明/提示
//
//对于 $100 \%$ 的数据：$2 \le n \leq 100$，$1 \le i, j, s, t \le n$，$1 \le m \leq 1000$。

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 110, M = 1010;

int n, m, s, t;
double x[N], y[N];

struct node
{
    int a, b;
    double c;
}e[M];

double calc(int i, int j)
{
    double dx = x[i] - x[j];
    double dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

double dist[N];

void bf()
{
    for(int i = 1; i <= n; i++) dist[i] = 1e10;

    dist[s] = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int a = e[j].a, b = e[j].b;
            double c = e[j].c;

            if(dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
            }

            if(dist[b] + c < dist[a])
            {
                dist[a] = dist[b] + c;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b;
        e[i].a = a; e[i].b = b; e[i].c = calc(a, b);
    }
    cin >> s >> t;

    bf();

    printf("%.2lf\n", dist[t]);

    return 0;
}
