//# P5266 �����17.��6��ѧ������
//
//## ��Ŀ����
//
//��Ҫ���һ��ѧ������ϵͳ���ʼѧ�������ǿյģ�Ȼ���ϵͳ�ܹ�֧������Ĳ����������� $10^5$ ������
//
//- �������޸ģ���ʽ`1 NAME SCORE`����ϵͳ�в�������Ϊ NAME(����ĸ��������ɲ����� 20 ���ַ����ַ��������ִ�Сд) ������Ϊ $\texttt{SCORE}$��$0<\texttt{SCORE}<2^{31}$�� ��ѧ��������Ѿ���ͬ����ѧ�����������ѧ���ĳɼ�Ϊ SCORE������ɹ���������޸������`OK`��
//- ��ѯ����ʽ`2 NAME`����ϵͳ�в�ѯ����Ϊ NAME ��ѧ���ĳɼ������û���ҵ�����ѧ�������`Not found`��������������ɼ���
//- ɾ������ʽ`3 NAME`����ϵͳ��ɾ������Ϊ NAME ��ѧ����Ϣ�����û���ҵ�����ѧ�������`Not found`���������`Deleted successfully`��
//- ���ܣ���ʽ`4`�����ϵͳ��ѧ��������
//
//## �����ʽ
//
//��
//
//## �����ʽ
//
//��
//
//## ����������� #1
//
//### ���� #1
//
//```
//5
//1 lxl 10
//2 lxl
//3 lxl
//2 lxl
//4
//```
//
//### ��� #1
//
//```
//OK
//10
//Deleted successfully
//Not found
//0
//```

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> mp;

    int T;
    cin >> T;

    while(T--)
    {
        int op;
        string name;
        cin >> op;
        if(op == 1)//���� + �޸�
        {
            cin >> name;
            int x;
            cin >> x;
            mp[name] = x;
            cout << "OK" << endl;
        }
        else if(op == 2)//��ѯ
        {
            cin >> name;
            if(mp.count(name)) cout << mp[name] << endl;
            else cout << "Not found" << endl;
        }
        else if(op == 3)//ɾ��
        {
            cin >> name;
            if(mp.count(name))
            {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
                cout << "Not found" << endl;
        }
        else
        {
            cout << mp.size() << endl;
        }
    }

    return 0;
}
