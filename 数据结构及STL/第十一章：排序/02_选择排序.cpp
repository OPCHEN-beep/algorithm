//ѡ������
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

void selection_sort()
{
    for(int i = 1; i < n; i++)//�������������λ��
    {
        //[i, n]�Ǵ����������
        int pos = i;
        for(int j = i + 1; j <= n; i++)
        {
            if(a[j] < a[pos])
            {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    selection_sort();

    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
