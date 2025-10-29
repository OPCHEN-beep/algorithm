//哈夫曼编码
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC233601
//时间限制：C/C++/Rust/Pascal 2秒，其他语言4秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//给出一个有
//n
//n种字符组成的字符串，其中第
//i
//i种字符出现的次数为
//a
//i
//a 
//i
//?
// 。请你对该字符串应用哈夫曼编码，使得该字符串的长度尽可能短，求编码后的字符串的最短长度。
//输入描述:
//第一行输入一个整数
//n
//n (
//1
//≤
//n
//≤
//2
//?
//1
//0
//5
//1≤n≤2?10 
//5
// )，表示字符种数。
//第二行输入
//n
//n个整数
//a
//i
//a 
//i
//?
//  (
//1
//≤
//a
//i
//≤
//1
//0
//9
//1≤a 
//i
//?
// ≤10 
//9
// )，表示每种字符的出现次数。
//输出描述:
//输出一行一个整数，表示编码后字符串的最短长度。
//示例1
//输入
//复制
//3
//1 2 3
//输出
//复制
//9
//说明
//三种字符的哈夫曼编码分别为["00","01","1"]时，长度最短，最短长度为9。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;
priority_queue<LL, vector<LL>, greater<LL>> heap;  //小根堆

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        LL x;
        cin >> x;
        heap.push(x);
    }
    
    LL len = 0;
    while(heap.size() > 1)
    {
        //每次拿出权值最小的两棵树合并
        LL x = heap.top();
        heap.pop();
        LL y = heap.top();
        heap.pop();
        LL t = x + y;
        len += t;
        heap.push(t);
    }
    
    cout << len << endl;
    
    return 0;
}
