//# B2122 ���ʷ�ת
//
//## ��Ŀ����
//
//С��ͬѧд���ʵ�ʱ��ϲ������д������ `hello` ����д�� `olleh`������С��ͬѧд��һ�����ӣ����㽫���еĵ��ʸ�ԭ��
//
//## �����ʽ
//
//��һ�У�һ���ַ�����ʾ���ӣ�����֮���Կո�ָ���
//
//## �����ʽ
//
//ÿ������һ�С�
//
//## ����������� #1
//
//### ���� #1
//
//```
//olleh dlrow
//```
//
//### ��� #1
//
//```
//hello
//world
//```
//
//## ˵��/��ʾ
//
//���ӳ��Ȳ����� $100$��������Сд��ĸ�Ϳո񣬲����ڶ���Ŀո�


#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//    string str;
//    while(cin >> str)
//    {
//        int left = 0;
//        int right = str.size() - 1;
//        //�ֶ�����
//        while(left < right)
//        {
//            char tmp = str[left];
//            str[left] = str[right];
//            str[right] = tmp;
//            left++;
//            right--;
//        }
//        cout << str << endl;
//    }
//
//    return 0;
//}


//��STL���и��㷨reverse����ֱ����ɷ�ת
#include <algorithm> 
int main()
{
	string s = "abcdef";
	reverse(s.begin(), s.end());
	cout << s << endl;
	
	return 0;
}
