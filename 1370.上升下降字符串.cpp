/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    string sortString(string s) {
        vector<int> num(26, 0);
        for (char &ch : s) num[ch - 'a']++;

        string ret;
        while (ret.length() < s.length()) {
            for (int i = 0; i < 26; i++) if (num[i]-- > 0) ret.push_back(i + 'a');
            for (int i = 25; i >= 0; i--) if (num[i] -- > 0) ret.push_back(i + 'a');
        }
        return ret;
    }
};
// @lc code=end

