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
////	//�����ַ���	 
////	string s1;					//���ַ��� 
////	string s2 = "hello world";	//��ʼ�����ַ��� 
////	cout << "s1:" << s1 << endl;
////	cout << "s2:" << s2 << endl;
//	
//	return 0;
//}


//string �ַ���������
//int main()
//{
////	string s;
////	cin >> s;	//�����ո��Զ�ֹͣ 
////	cout << s << endl; 
//	
//	//getline
//	string s1, s2;
//	getline(cin, s1);		//����'\n'ֹͣ 
//	cout << s1 << endl;
//	getline(cin, s2, 'q');	//����'q'ֹͣ 
//	cout << s2 << endl;
//	
//	return 0;
//} 


//size()����
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


//������
//int main()
//{
//	//������� 
//	string s = "abcdef";
//	for(string::iterator it = s.begin(); it < s.end(); it++)
//	{
//		cout << *it;
//	}
	
//	string::iterator it1 = s.begin();
//	string::iterator it2 = s.end();
//	
//	cout << *it1 << endl;	//������ 
//	it1++;
//	cout << *it1 << endl;	//������ 
//	it1--;
//	cout << *it1 << endl;	//������ 
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


//�ַ����� + �� += ����
//int main()
//{
//	//1.β��ƴ�� 
////	string s1 = "hello ";
////	cout << s1 + "world" << endl;
////	
////	s1 += "world";
////	cout << s1 << endl; 
//
//	//2.ͷ��ƴ��
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


//insert����
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


//string�Ĺ�ϵ����
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



//stoi��stol
//int main()
//{
////	//stoi��string����תint 
////	string s = "11x22";
////	size_t pos = 0;
//////	int r = stoi(s, &pos);	//Ĭ����Ϊs�е�������ʮ���Ƶ� 
////	int r = stoi(s, &pos, 2);//תΪ���������� 
////	cout << r << endl;
////	cout << "pos = " << pos << endl;
//
//	//stol��Ч��һ�� 
//	
//	return 0;
//}


//stod\stof���ַ���תdouble\float
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
