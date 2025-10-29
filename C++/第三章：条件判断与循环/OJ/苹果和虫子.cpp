//# P5709 【深基2.习6】Apples Prologue / 苹果和虫子
//
//## 题目描述
//
//小 B 喜欢吃苹果。她现在有 $m$（$1 \le m \le 100$）个苹果，吃完一个苹果需要花费 $t$（$0 \le t \le 100$）分钟，吃完一个后立刻开始吃下一个。现在时间过去了 $s$（$1 \le s \le 10000$）分钟，请问她还有几个完整的苹果？
//
//## 输入格式
//
//输入三个**非负整数**表示 $m, t, s$。
//
//## 输出格式
//
//输出一个整数表示答案。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//50 10 200
//```
//
//### 输出 #1
//
//```
//30
//```
//
//## 说明/提示
//
//如果你出现了 RE，不如检查一下被零除？


//错误答案： 
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int main()
//{
//    size_t m, t, s, n;
//    cin >> m >> t >> s;
//    if(t == 0)
//        n = 0;
//    else{
//        if(s % t == 0)
//            n = m - s/t;
//        else
//            n = m - s/t - 1;
//    }
//    printf("%d\n", n);
//
//    return 0;
//}


//正确答案：
#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	int m, t, s;
	int r;// 剩余的苹果数 
	//输入 
	cin >> m >> t >> s;
	
	//处理t为0的特殊情况
	if(0 == t)
	{
		cout << 0 << endl;
		return 0; //main函数直接返回 
	}
	
	//计算
	if(s % t == 0)
		r = (m - s / t < 0 ? 0 : m - s / t); 
	else
		r = (m - s / t - 1 < 0 ? 0 : m - s / t - 1);
	
	//输出 
	cout << r << endl;
	return 0;
}
