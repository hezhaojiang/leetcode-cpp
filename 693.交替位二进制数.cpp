/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int m = (n ^ (n >> 1));
        return ((m + 1) & m) == 0;
    }
};
// @lc code=end

