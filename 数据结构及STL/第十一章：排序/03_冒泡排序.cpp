//ð������
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

void bubble_sort()
{
    //����ö�ٴ�������������һ��Ԫ��
    for(int i = n; i > 1; i--)
    {
        bool flag = false;
        //[1�� i]���Ǵ���������
        for(int j = 1; j < i; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }

        if(flag == false)
            return;
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    bubble_sort();

    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
