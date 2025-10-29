//链接：https://ac.nowcoder.com/acm/problem/21595
//来源：牛客网
//
//题目描述 
//期中考试开始了，大家都想取得好成绩，争夺前五名。从键盘输入 n 个学生成绩，输出每组排在前五高的成绩。
//
//数据范围： 
//5
//≤
//??
//≤
//50
// 
//5≤n≤50  ，成绩采取百分制并不会出现负数
//输入描述:
//两行，第一行输入一个整数，表示n个学生（>=5），第二行输入n个学生成绩（整数表示，范围0~100），用空格分隔。
//输出描述:
//一行，输出成绩最高的前五个，用空格分隔。
//示例1
//输入
//复制
//6
//99 45 78 67 72 88
//输出
//复制
//99 88 78 72 67
//示例2
//输入
//复制
//5
//10 20 30 40 50
//输出
//复制
//50 40 30 20 10

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;
int arr[N];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, cmp);
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
