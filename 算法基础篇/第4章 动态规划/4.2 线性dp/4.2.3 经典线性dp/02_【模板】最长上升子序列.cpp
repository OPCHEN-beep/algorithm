//【模板】最长上升子序列
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC226831
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 256 M，其他语言512 M
//64bit IO Format: %lld
//题目描述 
//给你一个长度为n的数组，求最长的严格上升子序列的长度。
//输入描述:
//第一行一个整数n，表示数组长度。
//第二行n个整数，表示数组中的元素。
//
//1 <= n <= 100000
//输出描述:
//输出一行，表示答案。
//示例1
//输入
//复制
//5
//1 2 2 2 3
//输出
//复制
//3
//说明
//最长的上升子序列为[1,2,3]，长度为3.

#include <iostream>
using namespace std;

const int  N = 1e5 + 10;

int n;
int a[N];
int f[N], len;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        //处理边界情况
        if(len == 0 || a[i] > f[len]) f[++len] = a[i];
        else
        {
            //二分插入位置
            int l = 1, r = len;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(f[mid] >= a[i]) r = mid;
                else l = mid + 1;
            }
            
            f[l] = a[i];
        }
    }
    
    cout << len << endl;
    
    return 0;
}
