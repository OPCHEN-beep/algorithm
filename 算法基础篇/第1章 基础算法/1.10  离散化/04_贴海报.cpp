//# P3740 [HAOI2014] 贴海报
//
//## 题目描述
//
//Bytetown 城市要进行市长竞选，所有的选民可以畅所欲言地对竞选市长的候选人发表言论。为了统一管理，城市委员会为选民准备了一个张贴海报的 electoral 墙。
//
//张贴规则如下：
//
//1. electoral 墙是一个长度为 $N$ 个单位的长方形，每个单位记为一个格子；
//
//2. 所有张贴的海报的高度必须与 electoral 墙的高度一致的；
//
//3. 每张海报以 `A B` 表示，即从第 $A$ 个格子到第 $B$ 个格子张贴海报；
//
//4. 后贴的海报可以覆盖前面已贴的海报或部分海报。
//
//现在请你判断，张贴完所有海报后，在 electoral 墙上还可以看见多少张海报。
//
//## 输入格式
//
//第一行，两个正整数 $N,M$，分别表示 electoral 墙的长度和海报个数。
//
//接下来 $M$ 行，每行两个正整数 $A_i,B_i$，表示每张海报张贴的位置。
//
//## 输出格式
//
//输出贴完所有海报后，在 electoral 墙上还可以看见的海报数。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//100 5
//1 4
//2 6
//8 10
//3 4
//7 10
//```
//
//### 输出 #1
//
//```
//4
//```
//
//## 说明/提示
//
//![](https://cdn.luogu.com.cn/upload/pic/5209.png) 
//
//**约束条件**
//
//$10\le N \le 10000000,1\le M\le 1000,1\le A_i \le B_i \le 10000000$
//
//所有的数据都是正整数，数据之间有一个空格。\

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int a[N], b[N];

int pos;
int disc[N * 4];  //因为有两套位置

int w[N * 4];
bool mp[N];

//找到x映射之后的数，也就是x的下标
int find(int x)
{
    int l = 1, r = pos;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(disc[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x, b[i] = y;
        //离散化之后有可能导致区间缩小，多加一个位置
        disc[++pos] = x, disc[++pos] = x + 1;
        disc[++pos] = y, disc[++pos] = y + 1;
    }

    //离散化
    sort(disc + 1, disc + 1 + pos);
    pos = unique(disc + 1, disc + 1 + pos) - (disc + 1);

    //用离散化之后的值覆盖区间
    for(int i = 1; i <= m; i++)
    {
        int x = find(a[i]), y = find(b[i]);
        for(int j = x; j <= y; j++) w[j] = i;
    }

    //统计整个数组中，一共有多少个不同的数
    int cnt = 0;
    for(int i = 1; i <= pos; i++)
    {
        int x = w[i];
        if(!x) continue;  //不要统计0
        if(mp[x]) continue;
        cnt++;
        mp[x] = true;
    }

    cout << cnt << endl;

    return 0;
}
