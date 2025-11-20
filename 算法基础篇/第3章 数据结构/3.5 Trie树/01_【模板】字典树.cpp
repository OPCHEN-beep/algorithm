//# P8306 【模板】字典树
//
//## 题目描述
//
//给定 $n$ 个模式串 $s_1, s_2, \dots, s_n$ 和 $q$ 次询问，每次询问给定一个文本串 $t_i$，请回答 $s_1 \sim s_n$ 中有多少个字符串 $s_j$ 满足 $t_i$ 是 $s_j$ 的**前缀**。
//
//一个字符串 $t$ 是 $s$ 的前缀当且仅当从 $s$ 的末尾删去若干个（可以为 0 个）连续的字符后与 $t$ 相同。
//
//输入的字符串大小敏感。例如，字符串 `Fusu` 和字符串 `fusu` 不同。
//
//## 输入格式
//
//**本题单测试点内有多组测试数据**。  
//
//输入的第一行是一个整数，表示数据组数 $T$。
//
//对于每组数据，格式如下：  
//第一行是两个整数，分别表示模式串的个数 $n$ 和询问的个数 $q$。  
//接下来 $n$ 行，每行一个字符串，表示一个模式串。  
//接下来 $q$ 行，每行一个字符串，表示一次询问。
//
//## 输出格式
//
//按照输入的顺序依次输出各测试数据的答案。  
//对于每次询问，输出一行一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//3 3
//fusufusu
//fusu
//anguei
//fusu
//anguei
//kkksc
//5 2
//fusu
//Fusu
//AFakeFusu
//afakefusu
//fusuisnotfake
//Fusu
//fusu
//1 1
//998244353
//9
//```
//
//### 输出 #1
//
//```
//2
//1
//0
//1
//2
//1
//```
//
//## 说明/提示
//
//### 数据规模与约定
//
//对于全部的测试点，保证 $1 \leq T, n, q\leq 10^5$，且输入字符串的总长度不超过 $3 \times 10^6$。输入的字符串只含大小写字母和数字，且不含空串。
//
//### 说明
//std 的 IO 使用的是关闭同步后的 cin/cout，本题不卡常。

#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e6 + 10;

int n, q;
int tr[N][62], p[N];
int idx;

int get_num(char ch)
{
    if(ch >= 'a' && ch <= 'z') return ch - 'a';
    else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
    else return ch - '0' + 52;
}

void insert(string& s)
{
    int cur = 0;
    p[cur]++;

    for(auto ch : s)
    {
        int path = get_num(ch);
        if(tr[cur][path] == 0) tr[cur][path] = ++idx;

        cur = tr[cur][path];
        p[cur]++;
    }
}

int find_pre(string& s)
{
    int cur = 0;
    for(auto ch : s)
    {
        int path = get_num(ch);
        if(tr[cur][path] == 0) return 0;

        cur = tr[cur][path];
    }

    return p[cur];
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        for(int i = 0; i <= idx; i++)
        {
            for(int j = 0; j < 62; j++)
            {
                tr[i][j] = 0;
            }
        }

        for(int i = 0; i <= idx; i++) p[i] = 0;

        idx = 0;

        cin >> n >> q;
        while(n--)
        {
            string s; cin >> s;
            insert(s);
        }

        while(q--)
        {
            string s;
            cin >> s;
            cout << find_pre(s) << endl;
        }
    }

    return 0;
}
