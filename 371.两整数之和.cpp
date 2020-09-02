/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        return getSum(a ^ b, ((unsigned int)a & b) << 1);
    }
};
// @lc code=end

