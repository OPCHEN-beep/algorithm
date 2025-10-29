//CPP64 重载小于号
//题目
//题解(34)
//讨论(10)
//排行
//入门  通过率：45.66%  时间限制：1秒  空间限制：256M
//warning 校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
//描述
//有一个时间类（Time），成员变量有：小时（hours）、分钟（minutes），补充 Time 类的代码，重载小于号运算符，使得程序能够正确运行。
//输入描述：
//键盘输入两个整数，分别为小时 
//h
//h和分钟 
//m
//m，其中
//0
//≤
//m
//<
//60
//0≤m<60。
//输出描述：
//比较输入时间与6小时6分钟的大小，若输入时间较小则输出"yes"，否则输出"no"。
//示例1
//输入：
//6 5
//复制
//输出：
//yes

#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // 小时
        int minutes;    // 分钟

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void show() {
            cout << hours << " " << minutes << endl;
        }

        // write your code here......
        bool operator<(Time& t)
        {
            if(hours != t.hours)
            {
                return hours < t.hours;
            }
            else if(minutes != t.minutes)
            {
                return minutes < t.minutes;
            }
            else {
            return false;
            }
        }

};

int main() {
    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(6, 6);
	
    if (t1<t2) cout<<"yes"; else cout<<"no";
    return 0;
}
