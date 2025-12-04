//# B3644 【模板】拓扑排序 / 家谱树
//
//## 题目描述
//
//有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。给出每个人的后代的信息。输出一个序列，使得每个人的后辈都比那个人后列出。
//
//## 输入格式
//
//第 $1$ 行一个整数 $N$（$1 \le N \le 100$），表示家族的人数。接下来 $N$ 行，第 $i$ 行描述第 $i$ 个人的后代编号 $a_{i,j}$，表示 $a_{i,j}$ 是 $i$ 的后代。每行最后是 $0$ 表示描述完毕。
//
//## 输出格式
//
//输出一个序列，使得每个人的后辈都比那个人后列出。如果有多种不同的序列，输出任意一种即可。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//0
//4 5 1 0
//1 0
//5 3 0
//3 0
//```
//
//### 输出 #1
//
//```
//2 4 5 3 1
//```

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 110;

int n;
vector<int> edges[N];
int in[N];  //存储入度信息

int main()
{
    cin >> n;
    for(int i = 1;  i <= n; i++)
    {
        int j;
        while(cin >> j, j)
        {
            edges[i].push_back(j);
            in[j]++;  //统计入度信息
        }
    }

    //拓扑排序
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0) q.push(i);
    }

    while(q.size())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        //删除对应的边
        for(auto y : edges[x])
        {
            in[y]--;
            if(in[y] == 0) q.push(y);
        }
    }

    return 0;
}
