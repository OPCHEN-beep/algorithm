//# B2124 判断字符串是否为回文
//
//## 题目描述
//
//输入一个字符串，输出该字符串是否回文。回文是指顺读和倒读都一样的字符串。
//
//## 输入格式
//
//输入一行字符串，长度小于 $100$。
//
//## 输出格式
//
//如果字符串是回文，输出 `yes`；否则，输出 `no`。
//
//## 输入输出样例 #1
//
//### 输入 #1
//
//```
//abcdedcba
//```
//
//### 输出 #1
//
//```
//yes
//```

#include <iostream>
#include <string>

using namespace std;

//法一： 
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


//法二：逆序
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
