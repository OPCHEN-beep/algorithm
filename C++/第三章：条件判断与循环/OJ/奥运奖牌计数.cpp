//# B2058 ���˽��Ƽ���
//
//## ��Ŀ����
//
//$2008$ �걱�����˻ᣬA �����˶�Ա������ $n$ ��ľ�����Ŀ $(1 \le n \le 100)$������Ҫͳ��һ�� A ������õĽ�����ͭ����Ŀ���ܽ������������ $1$ ���� A �����������Ŀ������ $n$����� $n$ �У�ÿһ���Ǹù�ĳһ���õĽ�����ͭ����Ŀ�������� $100)$����� $4$ ��������Ϊ A ������õĽ�����ͭ���������ܽ�������
//
//## �����ʽ
//
//�� $1$ ���� A �����������Ŀ������ $n$����� $n$ �У�ÿһ���Ǹù�ĳһ���õĽ�����ͭ����Ŀ����һ���ո�ֿ���
//
//## �����ʽ
//
//��� $1$ �У����� $4$ ��������Ϊ A ������õĽ�����ͭ���������ܽ���������һ���ո�ֿ���
//
//## ����������� #1
//
//### ���� #1
//
//```
//3
//1 0 3
//3 1 0
//0 3 0
//```
//
//### ��� #1
//
//```
//4 4 3 11
//```

//�����:
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


//��ȷ��:
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
