//�ַ���
// ���
// 
// ����
// 
// �鿴���˵��ύ
// 
// �ҵ��ύ
//
//��ţ�NC18386
//ʱ�����ƣ�C/C++/Rust/Pascal 1�룬��������2��
//�ռ����ƣ�C/C++/Rust/Pascal 32 M����������64 M
//64bit IO Format: %lld
//��Ŀ���� 
//СN������һ���ַ���S������������ַ����������Ӵ������˳�����һ��S���Ӵ�T�ǺϷ��ģ����ҽ���T�а��������е�Сд��ĸ��СNϣ��֪�����еĺϷ���S���Ӵ��У���������Ƕ��١�
//��������:
//һ��һ���ַ���S��ֻ����Сд��ĸ��S�ĳ��Ȳ�����106.
//�������:
//һ��һ�����֣�������̳��ȡ����ݱ�֤����һ���Ϸ���S���Ӵ���
//ʾ��1
//����
//����
//ykjygvedtysvyymzfizzwkjamefxjnrnphqwnfhrnbhwjhqcgqnplodeestu
//���
//����
//49

#include <iostream>

using namespace std;

string s;
int mp[26];//ͳ��ÿ��Сд�ַ����ֵĴ���
int kind;//������Сд�ַ�������

int main()
{
    cin >> s;
    int n = s.size();
    int ret = n;
    
    //��ʼ��
    for(int left = 0, right = 0; right < n; right++)
    {
        //������
        if(mp[s[right] - 'a']++ == 0) kind++;
        //�ж�
        while(kind == 26)
        {
            //���½��
            ret = min(ret, right - left + 1);
            //������
            if(mp[s[left] - 'a']-- == 1) kind--;
            left++;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
