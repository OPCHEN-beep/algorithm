#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string s1("hello world");
//	string s2 = "hehe";
//	cout << s2 << endl;
//	s2 = s1;
//	cout << s2 << endl;
//	
//	
////	//创建字符串	 
////	string s1;					//空字符串 
////	string s2 = "hello world";	//初始化的字符串 
////	cout << "s1:" << s1 << endl;
////	cout << "s2:" << s2 << endl;
//	
//	return 0;
//}


//string 字符串的输入
//int main()
//{
////	string s;
////	cin >> s;	//遇到空格自动停止 
////	cout << s << endl; 
//	
//	//getline
//	string s1, s2;
//	getline(cin, s1);		//遇到'\n'停止 
//	cout << s1 << endl;
//	getline(cin, s2, 'q');	//遇到'q'停止 
//	cout << s2 << endl;
//	
//	return 0;
//} 


//size()函数
//int main()
//{
//	string s1;
//	string s2 = "hello";
//	string s3 = "hello world";
//	string s4 = "abc123     !#";
//	cout << s1.size() << endl; 
//	cout << s2.size() << endl; 
//	cout << s3.size() << endl; 
//	cout << s4.size() << endl; 
//	
//	return 0;
//} 


//迭代器
//int main()
//{
//	//正序遍历 
//	string s = "abcdef";
//	for(string::iterator it = s.begin(); it < s.end(); it++)
//	{
//		cout << *it;
//	}
	
//	string::iterator it1 = s.begin();
//	string::iterator it2 = s.end();
//	
//	cout << *it1 << endl;	//解引用 
//	it1++;
//	cout << *it1 << endl;	//解引用 
//	it1--;
//	cout << *it1 << endl;	//解引用 
//	cout << it2 - it1 << endl;
	
//	if(it1 < it2)
//	{
//		cout << "<" << endl; 
//	}
//	
//	else
//	{
//		cout << ">" << endl;
//	}
//	
//	return 0;
//}


//push_back()
//int main()
//{
//	string s;
//	s.push_back('h');
//	s.push_back('e');
//	s.push_back('l');
//	s.push_back('l');
//	s.push_back('o');
//	cout << s << endl;
//	
//	return 0;
// } 


//字符串的 + 和 += 运算
//int main()
//{
//	//1.尾部拼接 
////	string s1 = "hello ";
////	cout << s1 + "world" << endl;
////	
////	s1 += "world";
////	cout << s1 << endl; 
//
//	//2.头部拼接
//	string s2 = "hello";
//	s2 = "world" + s2; 
//	cout << s2 <<endl;
//	
//	return 0;
// } 


//pop_back()
//int main()
//{
//	string s = "hello";
//	s.pop_back();
//	cout << s << endl;
//	cout << s.size() << endl;
//	
//	return 0;
//}


//insert（）
//int main()
//{
////	string s = "abcdefghi";
////	string str = "xxx";
////	
////	cout << s << endl;
////	s.insert(3, str);
////	cout << s  << endl;
//
//	string s = "abcdefghi";
//	
//	cout << s << endl;
//	s.insert(3, 3, 'x');
//	cout << s << endl;
//	
//	return 0;
// } 


//find()
//int main()
//{
//	string s = "hello world hello everyone";
//	string str = "llo";
//	size_t n = s.find(str);
//	cout << n << endl;
//	
//	n = s.find(str, n + 1);
//	cout << n << endl;
//	
//	return 0;
//} 


//substr()
//int main()
//{
//	string s = "hello world hello everyone";
////	string s1 = s.substr();
////	string s1 = s.substr(7);
//	string s1 = s.substr(7, 6);
//	cout << s1 << endl;
//	
//	return 0;
////} 
//
//int main()
//{
//	string s = "hello world hello everyone";
//	size_t n = s.find("world");
//	string s1 = s.substr(n, 10);
//	cout << s1 << endl;
//	
//	return 0;
//}


//string的关系运算
//int main()
//{
//	string s1 = "hello world";
//	string s2 = "hello";
//	
//	if(s1 == s2 + "world")
//	{
//		cout << "==" << endl;
//	}
//	else
//	{
//		cout << "!=" << endl;
//	}
//	
//	return 0; 
// } 



//stoi、stol
//int main()
//{
////	//stoi：string类型转int 
////	string s = "11x22";
////	size_t pos = 0;
//////	int r = stoi(s, &pos);	//默认认为s中的数字是十进制的 
////	int r = stoi(s, &pos, 2);//转为二进制数字 
////	cout << r << endl;
////	cout << "pos = " << pos << endl;
//
//	//stol：效果一样 
//	
//	return 0;
//}


//stod\stof：字符串转double\float
//int main()
//{
//	string s = "3.14abc234";
//	size_t pos;
//	double d = stod(s, &pos);
//	cout << d << endl;
//	cout << "pos = " << pos << endl;
//	
//	return 0;
// } 
 
 
 
 //to_string
 int main()
 {
 	string s = to_string(3.14);
 	cout << s << endl;
 	
 	string pi = "pi is " + to_string(3.14);
  	cout << pi << endl;	
 	return 0;
 }
