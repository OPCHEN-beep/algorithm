//78. �Ӽ�
//�ѽ��
//�е�
//��ر�ǩ
//premium lock icon
//�����ҵ
//����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����
//
//�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��
//
// 
//
//ʾ�� 1��
//
//���룺nums = [1,2,3]
//�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//ʾ�� 2��
//
//���룺nums = [0]
//�����[[],[0]]
// 
//
//��ʾ��
//
//1 <= nums.length <= 10
//-10 <= nums[i] <= 10
//nums �е�����Ԫ�� ������ͬ

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        // ö�����е�״̬
        for(int st = 0; st < (1 << n); st++)
        {
            vector<int> tmp;
            for(int i = 0; i < n; i++)
            {
                if((st >> i) & 1) tmp.push_back(nums[i]);
            } 
            
            ret.push_back(tmp);
        } 
        
        return ret;
    }
};
