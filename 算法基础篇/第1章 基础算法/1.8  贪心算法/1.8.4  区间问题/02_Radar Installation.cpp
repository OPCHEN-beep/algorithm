//# UVA1193 Radar Installation
//
//## 题目描述
//
//[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=246&page=show_problem&problem=3634
//
//[PDF](https://uva.onlinejudge.org/external/11/p1193.pdf)
//
//描述：
//假设海岸线是一条无限长的直线，陆地位于海岸线的一边，大海位于海岸线的另一边。大海中有许多小岛。某安全部门为了监视这些岛上是否有敌人入侵，打算在海岸线上安装若干个雷达来检测岛屿的情况。每个雷达的覆盖范围是以雷达中心为圆心，半径为 d 的圆形区域。
//
//我们用平面之间坐标系来表示整个区域，海岸线为 x 轴，大海位于 x 轴上方，陆地位于 x 轴下方。为了节约成本，安全部门想使用最少的雷达覆盖所有的岛屿。现在已知每个岛屿的坐标 (x,y) 和雷达的覆盖半径 d，你的任务就是计算出能够覆盖所有岛屿的最少雷达数量。
//
//输入：
//输入包含若干组数据。
//
//每组数据的第一行有两个整数 n(1≤n≤1000) 和 d，分别表示岛屿的数量和雷达的覆盖半径，之后的 n 行，每行有两个整数，表示第 i 个岛屿的坐标 (x 
//i
//?
// ,y 
//i
//?
// )。
//
//相邻的两组数据使用一个空行隔开。输入 0 0 表示输入结束。
//
//输出：
//对于每一组数据的输出格式为 Case i: x，表示第 i 组数据中最少需要 x 个雷达来覆盖所有的岛屿；x=?1 表示这组数据无解（无法覆盖所有的岛屿）

//## 输入格式
//
//无
//
//## 输出格式
//
//无
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3 2
//1 2
//-3 1
//2 1
//
//1 2
//0 2
//
//0 0
//```
//
//### 输出 #1
//
//```
//Case 1: 2
//Case 2: 1
//```

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, d;

struct node
{
    double l, r;
}a[N];

bool cmp(node& x, node& y)
{
    return x.l < y.l;
}

int main()
{
    int cnt = 0;
    while(cin >> n >> d, n && d)
    {
        cnt++;
        bool flag = false;//有可能岛屿太远，无论如何也覆盖不到
        for(int i = 1; i <= n; i++)
        {
            double x, y;
            cin >> x >> y;
            if(y > d) flag == true;
            else
            {
                double t = sqrt(d * d - y * y);
                a[i].l = x - t, a[i].r = x + t;
            }
        }

        cout << "Case " << cnt << ": ";
        if(flag) cout << -1 << endl;
        else
        {
            sort(a + 1, a + 1 + n, cmp);
            int ret = 1;
            double r = a[1].r;
            for(int i = 2; i <= n; i++)
            {
                double x = a[i].l, y = a[i].r;
                if(x > r)  //没有重叠
                {
                    ret++;
                    r = y;
                }
                else
                {
                    //有重叠
                    r = min(r, y);
                }
            }

            cout << ret << endl;
        }
    }

    return 0;
}
