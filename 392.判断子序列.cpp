/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include<string>
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_index = 0;
        int t_index = 0;

        while(s_index != s.size() && t_index != t.size())
        {
            if(s[s_index] == t[t_index])
            {
                s_index++;
            }
            t_index++;
        }

        if(s.size() == s_index)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end

