/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int ans = 0;
        int product = 1;
        int left = 0, right = 0;
        while (right < nums.size()){
            product *= nums[right];
            while (product >= k) product = product / nums[left++];
            ans += right++ - left + 1;
        }
        return ans;
    }
};
// @lc code=end

