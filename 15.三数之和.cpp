/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        /* 小于3个元素直接返回 */
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) return result;
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    result.emplace_back(vector<int> {nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++, right--;
                }
                else if(sum > 0)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
// @lc code=end

