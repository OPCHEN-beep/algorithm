//���ӣ�https://ac.nowcoder.com/acm/contest/19304/O
//��Դ��ţ����
//
//��Ŀ���� 
//���������ϣ�ͨ���� 
//3
//��
//5
//3��5 ��Ϊ���� (spring)��
//6
//��
//8
//6��8 ��Ϊ�ļ� (summer)��
//9
//��
//11
//9��11 ��Ϊ�＾ (autumn)��
//12
//12 �������� 
//2
//2 ��Ϊ���� (winter)���������������£���ʽ YYYYMM�������Ӧ�ļ��ڡ�
//��������:
//��һ��������һ����λ���� YYYYMM����ʾ��ݺ��·ݣ����� YYYY Ϊ��λ��ݣ�MM Ϊ��λ�·ݣ�01~12����
//�������:
//���һ���ַ�����Ϊ��Ӧ�ļ���Ӣ�����ƣ�ȫ��Сд��ĸ������ "spring"��"summer"��"autumn" �� "winter"��������˫���ţ���
//ʾ��1
//����
//����
//201901
//���
//����
//winter
//˵��
//���� 201901 ��ʾ 2019 �� 1 �£�1 ��Ϊ��������� winter��
//ʾ��2
//����
//����
//202506
//���
//����
//summer
//˵��
//���� 202506 ��ʾ 2025 �� 6 �£�6 ��Ϊ�ļ������ summer��


//����𰸣� 
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


//��ȷ��:
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
