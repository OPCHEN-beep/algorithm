//取石子游戏
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC50617
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//小H和小Z正在玩一个取石子游戏。取石子游戏的规则是这样的，每个人每次可以从一堆石子中取出若干个石子，每次取石子的个数有限制，谁不能取石子时就会输掉游戏。小H先进行操作，他想问你他是否有必胜策略，如果有，第一步如何取石子。
//输入描述:
//第一行为石子的堆数N。
//接下来N行，每行一个数
//A
//i
//A 
//i
//?
// ，表示每堆石子的个数，接下来一行为每次取石子个数的种类数M。
//接下来M行，每行一个数
//B
//i
//B 
//i
//?
// ，表示每次可以取的石子个数，
//输入保证这M个数按照递增顺序排列。
//输出描述:
//第一行为YES或者NO，表示小H是否有必胜策略。
//若结果为YES，则第二行包含两个数，第一个数表示从哪堆石子取，第二个数表示取多少个石子，若有多种答案，取第一个数最小的答案，若仍有多种答案，取第二个数最小的答案。
//示例1
//输入
//复制
//4
//7
//6
//9
//3
//2
//1
//2
//输出
//复制
//YES
//1 1
//说明
//样例中共有四堆石子，石子个数分别为7,6,9,3，每人每次可以从任何一堆石子中取出1个或者2个石子，小H有必胜策略，事实上只要从第一堆石子中取一个石子即可。
//备注:
//对于全部数据，
//N
//≤
//10
//,
//A
//i
//≤
//1000
//,
//M
//≤
//10
//,
//B
//i
//≤
//10
//N≤10,A 
//i
//?
// ≤1000,M≤10,B 
//i
//?
// ≤10。

#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 15, M = 1010;

int n, m;
int a[N], b[N];
int f[M];

int sg(int x)
{
    if(f[x] != -1) return f[x];
    
    unordered_set<int> mp;
    for(int j = 1; j <= m && x - b[j] >= 0; j++) mp.insert(sg(x-b[j]));
    
    for(int i = 0; ; i++)
        if(!mp.count(i))
            return f[x] = i;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    memset(f, -1, sizeof f);
    int s = 0;
    for(int i = 1; i <= n; i++) s ^= sg(a[i]);
    
    if(s == 0) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m && a[i] - b[j] >= 0; j++)
            {
                if((s ^ sg(a[i]) ^ sg(a[i] - b[j])) == 0)
                {
                    cout << i << " " << b[j] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
