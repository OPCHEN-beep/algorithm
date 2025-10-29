//快速排序
#include <iostream>
#include <ctime>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

//优化：选择一个基准元素
int get_random(int left, int right)
{
    return a[rand() % (right - left + 1) + left];
}

void quick_sort(int left, int right)
{
    if(left >= right)
        return;

    //1.选择一个基准元素
    int p = get_random(left, right);

    //2.三路划分
    int l = left - 1, i = left, r = right + 1;
    while(i < r)
    {
        if(a[i] < p)
            swap(a[++l], a[i++]);
        else if(a[i] == p)
            i++;
        else
            swap(a[--r], a[i]);
    }

    quick_sort(left, l);
    quick_sort(r, right);
}

int main()
{
    srand(time(0));
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    quick_sort(1, n);

    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
