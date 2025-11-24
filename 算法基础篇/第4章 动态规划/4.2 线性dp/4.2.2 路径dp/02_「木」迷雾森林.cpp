//「木」迷雾森林
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC53675
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 128 M，其他语言256 M
//64bit IO Format: %lld
//题目描述 
//赛时提示：保证出发点和终点都是空地
//
//帕秋莉掌握了一种木属性魔法
//这种魔法可以生成一片森林（类似于迷阵），但一次实验时，帕秋莉不小心将自己困入了森林
//帕秋莉处于地图的左下角，出口在地图右上角，她只能够向上或者向右行走
//
//现在给你森林的地图，保证可以到达出口，请问有多少种不同的方案
//
//答案对2333取模
//
//输入描述:
//第一行两个整数m , n表示森林是m行n列
//接下来m行，每行n个数，描述了地图
//0  -  空地
//1  -  树（无法通过）
//输出描述:
//一个整数表示答案
//示例1
//输入
//复制
//3 3
//0 1 0
//0 0 0
//0 0 0
//输出
//复制
//3
//备注:
//对于30%的数据，n,m≤100
//对于100%的数据，n,m≤3,000
//数据规模较大，请使用较快的输入方式，以下为快速读入模板
//
//template<class T>inline void read(T &res)
//{
//char c;T flag=1;
//while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
//while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
//}
//
//scanf("%d",&x)  ->  read(x)
//cin>>x -> read(x)
//
//（调用方式：read(要读入的数)）

#include <iostream>
using namespace std;

const int N = 3010, MOD = 2333;

int n, m;
int a[N][N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    //初始化
    f[n][0] = 1;
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 0)
                f[i][j] = (f[i][j - 1] + f[i + 1][j]) % MOD;
    
    cout << f[1][m] << endl;
    
    return 0;
}
