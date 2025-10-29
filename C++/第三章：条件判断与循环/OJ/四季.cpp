//链接：https://ac.nowcoder.com/acm/contest/19304/O
//来源：牛客网
//
//题目描述 
//气象意义上，通常以 
//3
//～
//5
//3～5 月为春季 (spring)，
//6
//～
//8
//6～8 月为夏季 (summer)，
//9
//～
//11
//9～11 月为秋季 (autumn)，
//12
//12 月至来年 
//2
//2 月为冬季 (winter)。请根据输入的年月（格式 YYYYMM）输出对应的季节。
//输入描述:
//在一行中输入一个六位整数 YYYYMM，表示年份和月份，其中 YYYY 为四位年份，MM 为两位月份（01~12）。
//输出描述:
//输出一个字符串，为对应的季节英文名称（全部小写字母），即 "spring"、"summer"、"autumn" 或 "winter"（均不含双引号）。
//示例1
//输入
//复制
//201901
//输出
//复制
//winter
//说明
//输入 201901 表示 2019 年 1 月，1 月为冬季，输出 winter。
//示例2
//输入
//复制
//202506
//输出
//复制
//summer
//说明
//输入 202506 表示 2025 年 6 月，6 月为夏季，输出 summer。


//错误答案： 
//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int main()
//{
//    int x;
//    char fes;
//    cin >> x;
//    if(x == )
//    
//    return 0;
//}


//正确答案:
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int y,m;
    cin >> y;
    m = y % 100;
    
    switch(m)
    {
        case 3:
        case 4:
        case 5:
            cout << "spring" << endl;
            break;
        case 6:
        case 7:
        case 8:
            cout << "summer" << endl;
            break;
        case 9:
        case 10:
        case 11:
            cout << "autumn" << endl;
            break;
        case 12:
        case 1:
        case 2:
            cout << "winter" << endl;
            break;
    }

    return 0;
} 
