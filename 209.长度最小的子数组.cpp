/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int sum = 0;
        int length = INT_MAX;
        for(int i = 0, j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while(sum - nums[i] >= s)
            {
                sum -= nums[i++];
            }
            if(sum >= s) length = min(length, j - i + 1);
        }
        return length==INT_MAX?0:length;
    }
};
// @lc code=end

