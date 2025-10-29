//# B3623 枚举排列（递归实现排列型枚举）
//
//## 题目描述
//
//今有 $n$ 名学生，要从中选出 $k$ 人排成一列拍照。
//
//请按字典序输出所有可能的排列方式。
//
//## 输入格式
//
//仅一行，两个正整数 $n, k$。
//
//## 输出格式
//
//若干行，每行 $k$ 个正整数，表示一种可能的队伍顺序。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 2
//```
//
//### 输出 #1
//
//```
//1 2
//1 3
//2 1
//2 3
//3 1
//3 2
//```
//
//## 说明/提示
//
//对于 $100\%$ 的数据，$1\leq k\leq n \leq 10$。

#include <iostream>
#include <vector>

using namespace std;

const int N = 15;

int n, k;
vector<int> path;
bool st[N];  //标记一下哪些数已经选过了
void dfs()
{
    if(path.size() == k)
    {
        for(auto x : path) cout << x << " ";
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(st[i]) continue;
        path.push_back(i);
        st[i] = true;
        dfs();
        //恢复现场
        path.pop_back();
        st[i] = false;
    }
}

int main()
{
    cin >> n >> k;

    dfs();

    return 0;
}
