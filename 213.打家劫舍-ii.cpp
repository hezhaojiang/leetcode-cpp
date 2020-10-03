/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    int rob(vector<int>& nums, int start, int end) {
        vector<int> money(1, 0);
        for(int i = start; i < end; i++) {
            if(i == start) money.push_back(nums[i]);
            else money.push_back(max(money[i - start - 1] + nums[i], money[i - start]));
        }
        return money.back();
    }
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        return max(rob(nums, 0, N - 1), rob(nums, 1, N));
    }
};
// @lc code=end

