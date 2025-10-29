//矩阵消除游戏
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC200190
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//牛妹在玩一个名为矩阵消除的游戏，矩阵的大小是
//n
//n行
//m
//m列，第
//i
//i行第
//j
//j列的单元格的权值为
//a
//i
//,
//j
//a 
//i,j
//?
// ，牛妹可以进行
//k
//k个回合的游戏，在每个回合，牛妹可以选择一行或者选择一列，然后将这一行或者这一列的所有单元格中的权值变为
//0
//0，同时牛妹的分数会加上这一行或者这一列中的所有单元格的权值的和。
//
//牛妹想最大化她的得分，球球你帮帮她吧！
//
//输入描述:
//第一行三个整数
//n
//,
//m
//,
//k
//n,m,k
//接下来
//n
//n行每行
//m
//m个整数表示矩阵中各个单元格的权值。
//输出描述:
//输出一个整数表示牛妹能获得的最大分数。
//示例1
//输入
//复制
//3 3 2
//101 1 102
//1 202 1
//100 8 100
//输出
//复制
//414
//备注:
//1
//≤
//n
//,
//m
//≤
//15
//1≤n,m≤15
//1
//≤
//a
//i
//,
//j
//≤
//1
//e
//6
//1≤a 
//i,j
//?
// ≤1e6
//1
//≤
//k
//≤
//n
//?
//m
//1≤k≤n?m

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n, m, k;
int a[N][N];
int col[N];  //统计列和

//统计x的二进制表示中1的个数
int calc(int x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x -= x & -x;
    }
    return ret;
}

//按照值从大到小排序
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    int ret = 0;
    //暴力枚举出行的所有选法
    for(int st = 0; st < (1 << n); st++)
    {
        int cnt = calc(st);
        if(cnt > k) continue;  //不合法的状态
        
        memset(col, 0, sizeof col);
        int sum = 0;  //记录当前选法中的和
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((st >> i) & 1) sum += a[i][j];
                else col[j] += a[i][j];
            }
        }
        
        //处理列
        sort(col, col + m, cmp);
        //选 k - cnt 列
        for(int i = 0; i < k - cnt; i++) sum += col[i];
        ret = max(ret, sum);
    }
    cout << ret << endl;
    
    return 0;
}
