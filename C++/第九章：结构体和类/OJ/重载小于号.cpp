//CPP64 ����С�ں�
//��Ŀ
//���(34)
//����(10)
//����
//����  ͨ���ʣ�45.66%  ʱ�����ƣ�1��  �ռ����ƣ�256M
//warning У��ʱ������ҵ���Խ���ֹ���������ҳ�棬Ϊ��ǰ��Ӧ����ϰʱ��ʹ�������Բ⣬���Ǳ���IDE��
//����
//��һ��ʱ���ࣨTime������Ա�����У�Сʱ��hours�������ӣ�minutes�������� Time ��Ĵ��룬����С�ں��������ʹ�ó����ܹ���ȷ���С�
//����������
//�������������������ֱ�ΪСʱ 
//h
//h�ͷ��� 
//m
//m������
//0
//��
//m
//<
//60
//0��m<60��
//���������
//�Ƚ�����ʱ����6Сʱ6���ӵĴ�С��������ʱ���С�����"yes"���������"no"��
//ʾ��1
//���룺
//6 5
//����
//�����
//yes

#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // Сʱ
        int minutes;    // ����

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
