//���ӣ�https://ac.nowcoder.com/acm/contest/19304/D
//��Դ��ţ����
//
//��Ŀ���� 
//����ѧ���˳���������֪������m�ܷ�����n������
//��������:
//�����һ�У���������������Χ1 ~231-1������һ��Ϊm���ڶ���Ϊn��
//�������:
//�����һ�У�m �ܱ� n ������� YES��������� NO��
//ʾ��1
//����
//����
//36 6
//���
//����
//YES

#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
    size_t m, n;
    scanf("%d %d", &m, &n);
    if(m % n == 0)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}
// 64 λ������� printf("%lld")

