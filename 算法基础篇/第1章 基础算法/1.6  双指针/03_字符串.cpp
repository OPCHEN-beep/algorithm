//字符串
// 题解
// 
// 讨论
// 
// 查看他人的提交
// 
// 我的提交
//
//题号：NC18386
//时间限制：C/C++/Rust/Pascal 1秒，其他语言2秒
//空间限制：C/C++/Rust/Pascal 32 M，其他语言64 M
//64bit IO Format: %lld
//题目描述 
//小N现在有一个字符串S。他把这这个字符串的所有子串都挑了出来。一个S的子串T是合法的，当且仅当T中包含了所有的小写字母。小N希望知道所有的合法的S的子串中，长度最短是多少。
//输入描述:
//一行一个字符串S。只包含小写字母。S的长度不超过106.
//输出描述:
//一行一个数字，代表最短长度。数据保证存在一个合法的S的子串。
//示例1
//输入
//复制
//ykjygvedtysvyymzfizzwkjamefxjnrnphqwnfhrnbhwjhqcgqnplodeestu
//输出
//复制
//49

#include <iostream>

using namespace std;

string s;
int mp[26];//统计每个小写字符出现的次数
int kind;//窗口内小写字符的种类

int main()
{
    cin >> s;
    int n = s.size();
    int ret = n;
    
    //初始化
    for(int left = 0, right = 0; right < n; right++)
    {
        //进窗口
        if(mp[s[right] - 'a']++ == 0) kind++;
        //判断
        while(kind == 26)
        {
            //更新结果
            ret = min(ret, right - left + 1);
            //出窗口
            if(mp[s[left] - 'a']-- == 1) kind--;
            left++;
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
