//# B2124 �ж��ַ����Ƿ�Ϊ����
//
//## ��Ŀ����
//
//����һ���ַ�����������ַ����Ƿ���ġ�������ָ˳���͵�����һ�����ַ�����
//
//## �����ʽ
//
//����һ���ַ���������С�� $100$��
//
//## �����ʽ
//
//����ַ����ǻ��ģ���� `yes`��������� `no`��
//
//## ����������� #1
//
//### ���� #1
//
//```
//abcdedcba
//```
//
//### ��� #1
//
//```
//yes
//```

#include <iostream>
#include <string>

using namespace std;

//��һ�� 
int main()
{
    string s;
    cin >> s;
    int left = 0;
    int right = s.size() - 1;
    while(left < right)
    {
        if(s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;

    return 0;
}


//����������
int main()
{
	string s;
	cinn >> s;
	string t = s;
	reverse(t.begin(), t.end());
	if(s == t)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	return 0; 
 } 
