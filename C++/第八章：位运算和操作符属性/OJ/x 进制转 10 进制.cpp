//# B3620 x 进制转 10 进制
//
//## 题目描述
//
//给一个小整数 $x$ 和一个 $x$ 进制的数 $S$。将 $S$ 转为 $10$ 进制数。对于超过十进制的数码，用 `A`，`B`，$\ldots$ 表示。
//
//## 输入格式
//
//第一行一个整数 $x$;
//
//第二行一个字符串 $S$。
//
//## 输出格式
//
//输出仅包含一个整数，表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//16
//7B
//```
//
//### 输出 #1
//
//```
//123
//```
//
//## 说明/提示
//
//【数据规模和约定】  
//
//保证目标数在十进制下不超过 $10^9$，$1 \leq x \leq 36$。
//
//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    int x = 0;
//    string s;
//    cin >> x;
//    cin >> s;
//    int ret = 0;
//    int n = s.size();
//    int i = 0;
//    while(--n >= 0)
//    {
//        if (s[n] <= '9')
//            ret += (s[n] - '0') * pow(x, i);
//        else
//            ret += (s[n] + 10 - 'A') * pow(x, i);
//        i++;
//    }
//    cout << ret << endl;
//
//    return 0;
//}


//使用库函数
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x = 0;
    string s;
    cin >> x;
    cin >> s;
    int ret = 0;
    ret = stoi(s, NULL, x);
    cout << ret << endl;
    
    return 0;
}
