/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include<vector> 
using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for(int i = 0; i <= right;)
        {
            if(nums[i] == 0) swap(nums[i++], nums[left++]);
            else if(nums[i] == 2) swap(nums[i], nums[right--]);
            else i++;
        }
    }
};
// @lc code=end

