//# P1908 逆序对
//
//## 题目描述
//
//猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。
//
//最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 $a_i>a_j$ 且 $i<j$ 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。
//
//**Update：数据已加强。**
//
//## 输入格式
//
//第一行，一个数 $n$，表示序列中有 $n$ 个数。
//
//第二行 $n$ 个数，表示给定的序列。序列中每个数字不超过 $10^9$。
//
//## 输出格式
//
//输出序列中逆序对的数目。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//6
//5 4 2 6 3 1
//```
//
//### 输出 #1
//
//```
//11
//```
//
//## 说明/提示
//
//对于 $25\%$ 的数据，$n \leq 2500$。
//
//对于 $50\%$ 的数据，$n \leq 4 \times 10^4$。
//
//对于所有数据，$1 \leq n \leq 5 \times 10^5$。
//
//应该不会有人 $O(n^2)$ 过 50 万吧 —— 2018.8 chen_zhe。

#include <iostream>
using namespace std;
typedef long long LL;

const int N = 5e5 + 10;

int n;
int arr[N], tmp[N];

LL merge(int l, int r)
{
    if(l >= r) return 0;

    int mid = (l + r) / 2;

    LL ret = 0;
    ret += merge(l, mid);
    ret += merge(mid + 1, r);

    //计算一左一右时逆序对的个数
    int cur1 = l, cur2 = mid + 1, i = l;
    while(cur1 <= mid && cur2 <= r)
    {
        if(arr[cur1] <= arr[cur2])
        {
            tmp[i++] = arr[cur1++];
        }
        else  //右边元素比左边小时，产生逆序对
        {
            //统计逆序对的个数
            ret += (mid - cur1 + 1);
            tmp[i++] = arr[cur2++];
        }
    }
    while(cur1 <= mid) tmp[i++] = arr[cur1++];
    while(cur2 <= r) tmp[i++] = arr[cur2++];

    for(int j = l; j <= r; j++)
    {
        arr[j] = tmp[j];
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    cout << merge(1, n) << endl;

    return 0;
}
