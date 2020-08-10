/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        char c = s[0];
        int pre_c = 0;
        int cur_c = 1;
        int sub_c = 0;
        for (auto a : s.substr(1)) {
            if (a == c) cur_c++;
            else { sub_c += min(pre_c, cur_c); pre_c = cur_c; cur_c = 1; c = a; }
        }
        return sub_c + min(pre_c, cur_c);
    }
};
// @lc code=end

