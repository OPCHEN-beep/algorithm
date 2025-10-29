//����������Ϸ
// ���
// 
// ����
// 
// �鿴���˵��ύ
// 
// �ҵ��ύ
//
//��ţ�NC200190
//ʱ�����ƣ�C/C++/Rust/Pascal 1�룬��������2��
//�ռ����ƣ�C/C++/Rust/Pascal 256 M����������512 M
//64bit IO Format: %lld
//��Ŀ���� 
//ţ������һ����Ϊ������������Ϸ������Ĵ�С��
//n
//n��
//m
//m�У���
//i
//i�е�
//j
//j�еĵ�Ԫ���ȨֵΪ
//a
//i
//,
//j
//a 
//i,j
//?
// ��ţ�ÿ��Խ���
//k
//k���غϵ���Ϸ����ÿ���غϣ�ţ�ÿ���ѡ��һ�л���ѡ��һ�У�Ȼ����һ�л�����һ�е����е�Ԫ���е�Ȩֵ��Ϊ
//0
//0��ͬʱţ�õķ����������һ�л�����һ���е����е�Ԫ���Ȩֵ�ĺ͡�
//
//ţ����������ĵ÷֣������������ɣ�
//
//��������:
//��һ����������
//n
//,
//m
//,
//k
//n,m,k
//������
//n
//n��ÿ��
//m
//m��������ʾ�����и�����Ԫ���Ȩֵ��
//�������:
//���һ��������ʾţ���ܻ�õ���������
//ʾ��1
//����
//����
//3 3 2
//101 1 102
//1 202 1
//100 8 100
//���
//����
//414
//��ע:
//1
//��
//n
//,
//m
//��
//15
//1��n,m��15
//1
//��
//a
//i
//,
//j
//��
//1
//e
//6
//1��a 
//i,j
//?
// ��1e6
//1
//��
//k
//��
//n
//?
//m
//1��k��n?m

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;

int n, m, k;
int a[N][N];
int col[N];  //ͳ���к�

//ͳ��x�Ķ����Ʊ�ʾ��1�ĸ���
int calc(int x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x -= x & -x;
    }
    return ret;
}

//����ֵ�Ӵ�С����
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    int ret = 0;
    //����ö�ٳ��е�����ѡ��
    for(int st = 0; st < (1 << n); st++)
    {
        int cnt = calc(st);
        if(cnt > k) continue;  //���Ϸ���״̬
        
        memset(col, 0, sizeof col);
        int sum = 0;  //��¼��ǰѡ���еĺ�
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((st >> i) & 1) sum += a[i][j];
                else col[j] += a[i][j];
            }
        }
        
        //������
        sort(col, col + m, cmp);
        //ѡ k - cnt ��
        for(int i = 0; i < k - cnt; i++) sum += col[i];
        ret = max(ret, sum);
    }
    cout << ret << endl;
    
    return 0;
}
