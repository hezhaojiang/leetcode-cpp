/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubles = s.substr(1) + s.substr(0, s.length() - 1);
        string::size_type idx = doubles.find(s);
        if(idx == string::npos ) return false;
        return true;
    }
};
// @lc code=end

