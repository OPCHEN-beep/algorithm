//# UVA101 The Blocks Problem
//
//## 题目描述
//
//[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=37
//
//[PDF](https://uva.onlinejudge.org/external/1/p101.pdf)
//
//![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/4657c698576c8c299dbbf5655d7dbe63bf148978.png)
//
//## 输入格式
//
//![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/0a0a9b4a15235d9e81d83d5d31ee89ce48870fed.png)
//
//## 输出格式
//
//![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA101/ca24bcd0ff3af9dc6c1fcefd73c87532e9e05bd4.png)
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//10
//move 9 onto 1
//move 8 over 1
//move 7 over 1
//move 6 over 1
//pile 8 over 6
//pile 8 over 5
//move 2 over 1
//move 4 over 9
//quit
//```
//
//### 输出 #1
//
//```
//0: 0
//1: 1 9 2 4
//2:
//3: 3
//4:
//5: 5 8 7 6
//6:
//7:
//8:
//9:
//```

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> PII;

void clean(int x, int y)
{
    //把[x, y]以上的木块归位
    for(int j = y + 1; j < p[x].size(); j++)
    {
        int t = p[x][j];
        p[t].push_back(t);
    }
    p[x].resize(y + 1);
}

void move(int x1, int y1, int x2)
{
    //把[x1, y1]及其以上的木块放在x2上面
    for(int j = y1; j < p[x1].size(); j++)
    {
        p[x2].push_back(p[x1][j]);
    }
    p[x1].resize(y1);
}

int main()
{
    cin >> n;
    //初始化
    for(int i = 0; i < n; i++)
    {
        p[i].push_back(i);
    }

    string op1, op2;
    int a, b;

    while(cin >> op1 >> a >> op2 >> b)
    {
        //查找a和b的位置
        PII a = find(a);
        int x1 = pa.first, y1 = pa.second;
        PII pb = find(b);
        int x2 = pb.first, y2 = pb.second;

        //处理不合法的操作
        if(x1 == x2) continue;

        if(op1 == "move")//把a上方归位
        {
            clean(x1, y1);
        }    
        if(op2 == "onto")//把b上分归位
        {
            clean(x2, y2);
        }

        move(x1, y1, x2);
    }
    //打印
    for(int i = 0; i < n; i++)
    {
        cout << i << ":";
        for(int j = 0; j < p[i].size(); j++)
        {
            cout << " " << p[i][j];
        }
        cout << endl;
    }

    return 0;
}
