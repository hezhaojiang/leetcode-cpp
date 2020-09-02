/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto c : s) res ^= c;
        for (auto c : t) res ^= c;
        return res;
    }
};
// @lc code=end

