/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int distance = INT_MAX;
        int result = 0;
        /* 小于3个元素直接返回 */
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(distance > abs(sum - target))
                {
                    distance = abs(sum - target);
                    result = sum;
                }
                if(sum == target)
                    return sum;
                else if(sum > target)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
// @lc code=end

