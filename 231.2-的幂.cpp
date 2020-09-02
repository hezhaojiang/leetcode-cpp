/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0 || n == INT_MIN) return false;
        return (n & (n - 1)) == 0;
    }
};
// @lc code=end

