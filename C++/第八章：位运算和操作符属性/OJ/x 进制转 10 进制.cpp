//# B3620 x ����ת 10 ����
//
//## ��Ŀ����
//
//��һ��С���� $x$ ��һ�� $x$ ���Ƶ��� $S$���� $S$ תΪ $10$ �����������ڳ���ʮ���Ƶ����룬�� `A`��`B`��$\ldots$ ��ʾ��
//
//## �����ʽ
//
//��һ��һ������ $x$;
//
//�ڶ���һ���ַ��� $S$��
//
//## �����ʽ
//
//���������һ����������ʾ�𰸡�
//
//## ����������� #1
//
//### ���� #1
//
//```
//16
//7B
//```
//
//### ��� #1
//
//```
//123
//```
//
//## ˵��/��ʾ
//
//�����ݹ�ģ��Լ����  
//
//��֤Ŀ������ʮ�����²����� $10^9$��$1 \leq x \leq 36$��
//
//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//int main()
//{
//    int x = 0;
//    string s;
//    cin >> x;
//    cin >> s;
//    int ret = 0;
//    int n = s.size();
//    int i = 0;
//    while(--n >= 0)
//    {
//        if (s[n] <= '9')
//            ret += (s[n] - '0') * pow(x, i);
//        else
//            ret += (s[n] + 10 - 'A') * pow(x, i);
//        i++;
//    }
//    cout << ret << endl;
//
//    return 0;
//}


//ʹ�ÿ⺯��
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int x = 0;
    string s;
    cin >> x;
    cin >> s;
    int ret = 0;
    ret = stoi(s, NULL, x);
    cout << ret << endl;
    
    return 0;
}
