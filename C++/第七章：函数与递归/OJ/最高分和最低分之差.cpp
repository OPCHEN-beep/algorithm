//链接：https://ac.nowcoder.com/acm/problem/25318
//来源：牛客网
//
//题目描述 
//输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。
//输入描述:
//两行，第一行为n，表示n个成绩，不会大于10000。
//
//第二行为n个成绩（整数表示，范围0~100），以空格隔开。
//输出描述:
//一行，输出n个成绩中最高分数和最低分数的差。
//示例1
//输入
//复制
//10
//98 100 99 97 95 99 98 97 96 100
//输出
//复制
//5

//#include <iostream>
//using namespace std;
//
//
//int arr[10010] = {0};
//int n = 0;
//
//int Calc(int n, int* arr)
//{
//    int max;
//    int min;
//    for(int i = 0; i < n; i++)
//    {
//        max = 0;
//        min = arr[i];
//        if(arr[i] > max)
//            max = arr[i];
//        if(arr[i] < min)
//            min = arr[i];
//    }
//    
//    return max - min;
//}
//
//int main()
//{
//    ios::sync_with_stdio(false); //取消给C语?输?输出缓冲区的同步
//    cin.tie(0); //取消了cin和cout的绑定
//    
//    cin >> n;
//    for(int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//    
//    cout << Calc(n, arr) << endl;
//
//    return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    int t;
    cin >> n;
    cin >> t;
    int maxNum = t, minNum = t;
    for(int i = 1; i <n; i++)
    {
        cin >> t;
        maxNum = max(maxNum, t);
        minNum = min(minNum, t);
    }
    cout << maxNum - minNum << endl;
    
    return 0;
}
