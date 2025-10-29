#include <iostream>
#include <cstring>

using namespace std;
//int main()
//{
//	char arr[] = "hello world";
//	cout << arr << endl;
//	
//	//memset(arr, 'x', 5);
//	//cout << arr << endl;
//	
//	memset(arr + 2, 'x', 5);
//	cout << arr << endl;
//	
//	return 0;
//}

//int main()
//{
//	int arr[5]{1, 2, 3, 4, 5};
//	memset(arr, 0, 20);
//	
//	for(int e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	
//	return 0;
//}


int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {0};
	for(int e : b)
	{
		cout << e << " ";
	}
	cout << endl;
	
	memcpy(b, a, 10 * sizeof(int));
	for(int e : b)
	{
		cout << e << " ";
	}
	cout << endl;
	
	
	
	return 0;
}
