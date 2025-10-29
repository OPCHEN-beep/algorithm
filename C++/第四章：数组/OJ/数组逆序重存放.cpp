//# B2089 数组逆序重存放
//
//## 题目描述
//
//将一个数组中的值按逆序重新存放。例如，原来的顺序为 $8,6,5,4,1$。要求改为 $1,4,5,6,8$。
//
//## 输入格式
//
//输入为两行：第一行数组中元素的个数 $n$（$1 \lt n \le 100$)，第二行是 $n$ 个整数，每两个整数之间用空格分隔。
//
//## 输出格式
//
//输出为一行：输出逆序后数组的整数，每两个整数之间用空格分隔。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//8 6 5 4 1
//```
//
//### 输出 #1
//
//```
//1 4 5 6 8
//```


#include <iostream>
#include <cstdio>

using namespace std;

int arr[100] = {0};

int main()
{
    int n = 0;
    cin >> n;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //逆序
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
    
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
