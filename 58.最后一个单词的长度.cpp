/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include<string>
#include<vector>
#include<regex>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() == 0) return 0;
        regex ws_re("\\s+"); // whitespace
        vector<std::string> v(sregex_token_iterator(s.begin(), s.end(), ws_re, -1), 
            sregex_token_iterator());
        int len = 0;
        for (auto &s: v) len = s.length();
        return len;
    }
};
// @lc code=end

