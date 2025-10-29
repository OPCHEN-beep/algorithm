//20. ��Ч������
//�ѽ��
//��
//��ر�ǩ
//premium lock icon
//�����ҵ
//��ʾ
//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
// 
//
//ʾ�� 1��
//
//���룺s = "()"
//
//�����true
//
//ʾ�� 2��
//
//���룺s = "()[]{}"
//
//�����true
//
//ʾ�� 3��
//
//���룺s = "(]"
//
//�����false
//
//ʾ�� 4��
//
//���룺s = "([])"
//
//�����true
//
//ʾ�� 5��
//
//���룺s = "([)]"
//
//�����false
//
// 
//
//��ʾ��
//
//1 <= s.length <= 104
//s �������� '()[]{}' ���

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto ch : s)
        {
            if(ch == '[' || ch == '(' || ch == '{')
            {
                st.push(ch);
            }

            else
            {
                if(st.empty())
                    return false;
                char left = st.top();
                if(ch == ')' && left != '(')
                    return false;
                if(ch == ']' && left != '[')
                    return false;
                if(ch == '}' && left != '{')
                    return false;

                st.pop();
             }
        }
        return st.empty();
    }
};
