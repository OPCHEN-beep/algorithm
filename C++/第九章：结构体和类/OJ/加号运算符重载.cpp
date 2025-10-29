//CPP43 �Ӻ����������
//��Ŀ
//���(49)
//����(17)
//����
//��  ͨ���ʣ�38.12%  ʱ�����ƣ�1��  �ռ����ƣ�256M
//warning У��ʱ������ҵ���Խ���ֹ���������ҳ�棬Ϊ��ǰ��Ӧ����ϰʱ��ʹ�������Բ⣬���Ǳ���IDE��
//����
//��һ��ʱ���ࣨTime������Ա�����У�Сʱ��hours�������ӣ�minutes�������� Time ��Ĵ��룬���ؼӺ��������ʹ�ó����ܹ���ȷ���С�
//����������
//���������������������ֱ�ΪСʱ h �ͷ��� m��Ҫ����� m ��ΧΪ 0 - 59
//���������
//������� Time ����t1 �� t2����Ӻ��ʱ������ͨ������ show() �����
//ʾ��1
//���룺
//1
//10
//����
//�����
//3 30
//����
//ʾ��2
//���룺
//2
//50
//����
//�����
//5 10

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
