//# P3378 【模板】堆
//
//## 题目描述
//
//给定一个数列，初始为空，请支持下面三种操作：
//
//1. 给定一个整数 $x$，请将 $x$ 加入到数列中。
//2. 输出数列中最小的数。
//3. 删除数列中最小的数（如果有多个数最小，只删除 $1$ 个）。
//
//## 输入格式
//
//第一行是一个整数，表示操作的次数 $n$。  
//接下来 $n$ 行，每行表示一次操作。每行首先有一个整数 $op$ 表示操作类型。
//- 若 $op = 1$，则后面有一个整数 $x$，表示要将 $x$ 加入数列。
//- 若 $op = 2$，则表示要求输出数列中的最小数。
//- 若 $op = 3$，则表示删除数列中的最小数。如果有多个数最小，只删除 $1$ 个。
//
//## 输出格式
//
//对于每个操作 $2$，输出一行一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//5
//1 2
//1 5
//2
//3
//2
//```
//
//### 输出 #1
//
//```
//2
//5
//```
//
//## 说明/提示
//
//**【数据规模与约定】**
//- 对于 $30\%$ 的数据，保证 $n \leq 15$。
//- 对于 $70\%$ 的数据，保证 $n \leq 10^4$。
//- 对于 $100\%$ 的数据，保证 $1 \leq n \leq 10^6$，$1 \leq x \lt 2^{31}$，$op \in \{1, 2, 3\}$。

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int heap[N];

//向上调整算法
void up(int child)
{
    int parent = child / 2;

    while(parent >= 1 && heap[child] < heap[parent])
    {
        swap(heap[child], heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

//向下调整算法
void down(int parent)
{
    int child = parent * 2;

    while(child <= n)
    {
        //找出两个孩子中的最小值
        if(child + 1 <= n && heap[child + 1] < heap[child]) child++;

        if(heap[child] >= heap[parent]) return;

        swap(heap[child], heap[parent]);
        parent = child;
        child = parent * 2;
    }
}

//进堆
void push(int x)
{
    n++;
    heap[n] = x;

    up(n);
}

void pop()
{
    swap(heap[1], heap[n]);
    n--;

    down(1);
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int op;
        cin >> op;

        if(op == 1)//进堆
        {
            int x; cin >> x;
            push(x);
        }
        else if(op == 2)//输出堆顶
        {
            cout << heap[1] << endl;
        }
        else//删除堆顶元素
        {
            pop();
        }
    }

    return 0;
}
