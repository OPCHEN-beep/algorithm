//���ӣ�https://ac.nowcoder.com/acm/problem/25318
//��Դ��ţ����
//
//��Ŀ���� 
//����n���ɼ����������n���ɼ�����߷�������ͷ����Ĳ
//��������:
//���У���һ��Ϊn����ʾn���ɼ����������10000��
//
//�ڶ���Ϊn���ɼ���������ʾ����Χ0~100�����Կո������
//�������:
//һ�У����n���ɼ�����߷�������ͷ����Ĳ
//ʾ��1
//����
//����
//10
//98 100 99 97 95 99 98 97 96 100
//���
//����
//5

//#include <iostream>
//using namespace std;
//
//
//int arr[10010] = {0};
//int n = 0;
//
//int Calc(int n, int* arr)
//{
//    int max;
//    int min;
//    for(int i = 0; i < n; i++)
//    {
//        max = 0;
//        min = arr[i];
//        if(arr[i] > max)
//            max = arr[i];
//        if(arr[i] < min)
//            min = arr[i];
//    }
//    
//    return max - min;
//}
//
//int main()
//{
//    ios::sync_with_stdio(false); //ȡ����C��?��?�����������ͬ��
//    cin.tie(0); //ȡ����cin��cout�İ�
//    
//    cin >> n;
//    for(int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//    
//    cout << Calc(n, arr) << endl;
//
//    return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    int t;
    cin >> n;
    cin >> t;
    int maxNum = t, minNum = t;
    for(int i = 1; i <n; i++)
    {
        cin >> t;
        maxNum = max(maxNum, t);
        minNum = min(minNum, t);
    }
    cout << maxNum - minNum << endl;
    
    return 0;
}
