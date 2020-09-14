/*
 * @lc app=leetcode.cn id=1227 lang=cpp
 *
 * [1227] 飞机座位分配概率
 */

// @lc code=start
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1? 1.0 : 0.5;
    }
};
// @lc code=end

