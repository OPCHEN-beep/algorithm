//第 k 小
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC214362
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//有一个长度为n的数组，值为 a[i], 牛牛想找到数组中第 k 小的数。比如 1 2 2 3 4  6 中，第 3 小的数就是2.
//牛牛觉得这个游戏太简单了，想加一点难度，现在牛牛有 m 个操作，每个操作有两种类型。
//1 x  1 代表操作一，给数组中加一个元素 x 。(0 ≤ x ≤ 1e9)
//2     2 代表操作二，查询第 k 小的数。如果没有 k 个数就输出?1
//输入描述:
//第一行有三个整数，n m k,(1≤n,m,k≤2e5)
//第二行包含 n 个整数 a[i] ( 0 ≤ a[i] ≤ 1e9)
//接下来m行，每行代表一个操作。具体见题目描述
//输出描述:
//每次查询输出一个第  k  小的数。
//
//
//示例1
//输入
//复制
//5 4 3
//1 2 3 4 5
//2
//1 1
//1 3
//2
//输出
//复制
//3
//2

#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
priority_queue<int> heap;

int main()
{
    cin >> n >> m >> k;
    
    for(int i =1; i <= n; i++)
    {
        int x;
        cin >> x;
        heap.push(x);
        if(heap.size() > k)
            heap.pop();
    }
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x;
            cin >> x;
            heap.push(x);
            if(heap.size() > k)
                heap.pop();
        }
        else if(op == 2)
        {
            if(heap.size() == k)
                cout << heap.top() << endl;
            else
                cout << -1 << endl;
        }
    }
    
    return 0;
}
