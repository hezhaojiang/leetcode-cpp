/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int R = 1, N = nums.size();
        vector<int> result(1, 1);
        for (int i = 1; i < N; ++i) result.push_back(result.back() * nums[i - 1]);
        for (int i = N - 2; i >= 0; --i) result[i] *= (R *= nums[i + 1]);
        return result;
    }
};
// @lc code=end

