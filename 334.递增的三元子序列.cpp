/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int oneMin = INT_MAX;
        int twoMax = INT_MAX;
        for(auto a : nums)
        {
            if(a < oneMin) oneMin = a;
            if(a > twoMax) return true;
            if(a > oneMin) twoMax = a;
        }
        return false;
    }
};
// @lc code=end

