#include <iostream>
using namespace std;


int arr[10010] = { 0 };
int n = 0;

int Calc(int n, int* arr)
{
    int max = 0;
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        max = 0;
        min = arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    return max - min;
}

int main()
{
    ios::sync_with_stdio(false); //取消给C语⾔输⼊输出缓冲区的同步
    cin.tie(0); //取消了cin和cout的绑定

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Calc(n, arr) << endl;

    return 0;
}