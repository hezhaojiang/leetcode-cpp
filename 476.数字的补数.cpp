/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int n = __builtin_clz(num);
        int i = 0x80000000;
        return ~(i >> n) & ~num;
    }
};
// @lc code=end

