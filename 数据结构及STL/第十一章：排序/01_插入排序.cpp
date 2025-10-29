//插入排序
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

void insert_sort()
{
    //依次枚举待排序的元素
    for(int i = 2; i <= n; i++)
    {
        int key = a[i];

        //前面比key大的，统一右移
        int j = i - 1;
        while(j >= 1 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    insert_sort();

    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
