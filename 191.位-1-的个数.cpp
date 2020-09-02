/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n == 0) return 0;
        return hammingWeight(n & (n - 1)) + 1;
    }
};
// @lc code=end

