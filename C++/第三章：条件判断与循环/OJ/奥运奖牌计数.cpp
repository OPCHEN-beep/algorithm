//# B2058 奥运奖牌计数
//
//## 题目描述
//
//$2008$ 年北京奥运会，A 国的运动员参与了 $n$ 天的决赛项目 $(1 \le n \le 100)$。现在要统计一下 A 国所获得的金、银、铜牌数目及总奖牌数。输入第 $1$ 行是 A 国参与决赛项目的天数 $n$，其后 $n$ 行，每一行是该国某一天获得的金、银、铜牌数目（不超过 $100)$。输出 $4$ 个整数，为 A 国所获得的金、银、铜牌总数及总奖牌数。
//
//## 输入格式
//
//第 $1$ 行是 A 国参与决赛项目的天数 $n$，其后 $n$ 行，每一行是该国某一天获得的金、银、铜牌数目，以一个空格分开。
//
//## 输出格式
//
//输出 $1$ 行，包括 $4$ 个整数，为 A 国所获得的金、银、铜牌总数及总奖牌数，以一个空格分开。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//3
//1 0 3
//3 1 0
//0 3 0
//```
//
//### 输出 #1
//
//```
//4 4 3 11
//```

//错误答案:
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int main()
//{
//    long long n;
//    long long a, b, c = 0;
//    long long cnta, cntb, cntc = 0; 
//    scanf("%lld\n", &n);
//    for(long long i = n; i > 0; i--)
//    {
//        scanf("%lld %lld %lld", &a, &b, &c);
//        cnta += a;
//        cntb += b;
//        cntc += c;
//    }
//    int cnt = cnta + cntb + cntc;
//    printf("%lld %lld %lld %lld\n", cnta, cntb, cntc, cnt);
//
//    return 0;
//} 


//正确答案:
#include <iostream>
#include <cstdio>
using namespace std;

int n, p1, p2, p3, sum, a, b, c;

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        p1 += a;
        p2 += b;
        p3 += c;
    }
    sum = p1 + p2 + p3;
    cout << p1 << " " << p2 << " " << p3 << " " << sum << endl;

    return 0;
} 
