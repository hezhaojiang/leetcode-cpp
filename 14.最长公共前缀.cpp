/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
                if(i == strs[j].length() || c != strs[j][i]) 
                    return strs[0].substr(0,i);
        }
        return strs[0];
    }
};
// @lc code=end

