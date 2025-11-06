#include <iostream> 
#include <stack>

using namespace std;

const int N = 3e6 + 10;
int a[N], n;
int ret[N];

//1.寻找当前元素左侧，离它最近，并且比它大的元素在哪
void test1()
{
	stack<int> st;  //维护一个单调递减的栈
	
	for(int i = 1; i <= n; i++)
	{
		//栈里面小于等于a[i]的元素全部出栈
		while(st.size() && a[st.top()] <= a[i]) st.pop();
		
		//此时栈顶元素存在，栈顶元素就是所求结果
		if(st.size()) ret[i] = st.top();
		
		st.push(i);  //存下标 
	} 
	
	for(int i = 1; i <= n; i++)
	{
		cout << ret[i] << " "; 
	}
	cout << endl;
}

//2.寻找当前元素左侧，离它最近，并且比它小的元素在哪
void test2()
{
	stack<int> st;  //单调递增 
	
	for(int i = 1; i <= n; i++)
	{
		//栈里面大于等于a[i]的元素全部出栈 
		while(st.size() && a[st.top()] >= a[i]) st.pop();
		
		if(st.size()) ret[i] = st.top();
		
		st.push(i);
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}

//3.寻找当前元素右侧，离它最近，并且比它大的元素在哪
void test3()
{
	stack<int> st;  //单调递减 
	
	for(int i = n; i >= 1; i--)
	{
		//栈里面小于等于a[i]的元素全部出栈 
		while(st.size() && a[st.top()] <= a[i]) st.pop();
		
		if(st.size()) ret[i] = st.top();
		
		st.push(i);
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}

//4.寻找当前元素右侧，离它最近，并且比它小的元素在哪
void test4()
{
	stack<int> st;  //单调递增 
	
	for(int i = n; i >= 1; i--)
	{
		//栈里面大于等于a[i]的元素全部出栈 
		while(st.size() && a[st.top()] >= a[i]) st.pop();
		
		if(st.size()) ret[i] = st.top();
		
		st.push(i);
	}
	
	for(int i = 1; i <= n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//test1();
	//test2();
	//test3();
	test4();
	
	cout << endl;
	
	return 0;
}
