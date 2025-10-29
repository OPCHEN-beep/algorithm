//�� k С
// ���
// 
// ����
// 
// �鿴���˵��ύ
// 
// �ҵ��ύ
//
//��ţ�NC214362
//ʱ�����ƣ�C/C++/Rust/Pascal 1�룬��������2��
//�ռ����ƣ�C/C++/Rust/Pascal 256 M����������512 M
//64bit IO Format: %lld
//��Ŀ���� 
//��һ������Ϊn�����飬ֵΪ a[i], ţţ���ҵ������е� k С���������� 1 2 2 3 4  6 �У��� 3 С��������2.
//ţţ���������Ϸ̫���ˣ����һ���Ѷȣ�����ţţ�� m ��������ÿ���������������͡�
//1 x  1 �������һ���������м�һ��Ԫ�� x ��(0 �� x �� 1e9)
//2     2 �������������ѯ�� k С���������û�� k ���������?1
//��������:
//��һ��������������n m k,(1��n,m,k��2e5)
//�ڶ��а��� n ������ a[i] ( 0 �� a[i] �� 1e9)
//������m�У�ÿ�д���һ���������������Ŀ����
//�������:
//ÿ�β�ѯ���һ����  k  С������
//
//
//ʾ��1
//����
//����
//5 4 3
//1 2 3 4 5
//2
//1 1
//1 3
//2
//���
//����
//3
//2

#include <iostream>
#include <queue>

using namespace std;

int n, m, k;
priority_queue<int> heap;

int main()
{
    cin >> n >> m >> k;
    
    for(int i =1; i <= n; i++)
    {
        int x;
        cin >> x;
        heap.push(x);
        if(heap.size() > k)
            heap.pop();
    }
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x;
            cin >> x;
            heap.push(x);
            if(heap.size() > k)
                heap.pop();
        }
        else if(op == 2)
        {
            if(heap.size() == k)
                cout << heap.top() << endl;
            else
                cout << -1 << endl;
        }
    }
    
    return 0;
}
