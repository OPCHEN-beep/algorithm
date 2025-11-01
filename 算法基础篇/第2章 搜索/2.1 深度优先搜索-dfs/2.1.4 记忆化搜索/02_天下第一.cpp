//# P5635 【CSGRound1】天下第一
//
//## 题目背景
//
//天下第一的 cbw 以主席的身份在 8102 年统治全宇宙后，开始了自己休闲的生活，并邀请自己的好友每天都来和他做游戏。由于 cbw 想要显出自己平易近人，所以 zhouwc 虽然是一个蒟蒻，也有能和 cbw 玩游戏的机会。
//
//## 题目描述
//
//游戏是这样的：
//
//给定两个数 $x$，$y$，与一个模数 $p$。
//
//cbw 拥有数 $x$，zhouwc 拥有数 $y$。
//
//第一个回合：$x\leftarrow(x+y)\bmod p$。
//
//第二个回合：$y\leftarrow(x+y)\bmod p$。
//
//第三个回合：$x\leftarrow(x+y)\bmod p$。
//
//第四个回合：$y\leftarrow(x+y)\bmod p$。
//
//以此类推....
//
//如果 $x$ 先到 $0$，则 cbw 胜利。如果 $y$ 先到 $0$，则 zhouwc 胜利。如果 $x,y$ 都不能到 $0$，则为平局。
//
//cbw 为了捍卫自己主席的尊严，想要提前知道游戏的结果，并且可以趁机动点手脚，所以他希望你来告诉他结果。
//
//## 输入格式
//
//有多组数据。
//
//第一行：$T$ 和 $p$ 表示一共有 $T$ 组数据且模数都为 $p$。
//
//以下 $T$ 行，每行两个数 $x,y$。
//
//## 输出格式
//
//共 $T$ 行
//
//$1$ 表示 cbw 获胜，$2$ 表示 zhouwc 获胜，```error``` 表示平局。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//1 10
//1 3
//```
//
//### 输出 #1
//
//```
//error
//```
//
//## 输入输出样例 #2
//
//### 输入 #2
//
//```
//1 10
//4 5
//```
//
//### 输出 #2
//
//```
//1
//```
//
//## 说明/提示
//
//$1 \leq T \leq 200$。
//
//$1 \leq x,y,p \leq 10000$。

#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int x, y, p;
char f[N][N];  //备忘录

char dfs(int x, int y)
{
    if(f[x][y]) return f[x][y];  //剪枝

    f[x][y] = '3';  //这个状态已经访问过了，之后再遇到时，表示平局

    if(x == 0) return f[x][y] = '1';
    if(y == 0) return f[x][y] = '2';
    return f[x][y] = dfs((x + y) % p, (x + y + y) % p);
}

int main()
{
    int T;
    cin >> T >> p;

    while(T--)
    {
        cin >> x >> y;
        char ret = dfs(x, y);
        if(ret == '1') cout << 1 << endl;
        else if(ret == '2') cout << 2 << endl;
        else cout << "error" << endl;
    }

    return 0;
}
