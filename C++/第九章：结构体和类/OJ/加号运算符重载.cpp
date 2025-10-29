//CPP43 加号运算符重载
//题目
//题解(49)
//讨论(17)
//排行
//简单  通过率：38.12%  时间限制：1秒  空间限制：256M
//warning 校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。
//描述
//有一个时间类（Time），成员变量有：小时（hours）、分钟（minutes），补充 Time 类的代码，重载加号运算符，使得程序能够正确运行。
//输入描述：
//键盘输入两个正整数，分别为小时 h 和分钟 m。要求分钟 m 范围为 0 - 59
//输出描述：
//输出两个 Time 对象（t1 和 t2）相加后的时间结果，通过调用 show() 输出。
//示例1
//输入：
//1
//10
//复制
//输出：
//3 30
//复制
//示例2
//输入：
//2
//50
//复制
//输出：
//5 10

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
        Time operator+(Time& t)
        {
            Time ret;
            int flag = 0;
            ret.minutes = minutes + t.minutes;
            if(ret.minutes >= 60)
            {
                ret.minutes -= 60;
                flag = 1;
            }
            ret.hours = hours + t.hours + flag;

            return ret;
        }        

};

int main() {

    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(2, 20);

    Time t3 = t1 + t2;
    t3.show();
    
    return 0;
}
