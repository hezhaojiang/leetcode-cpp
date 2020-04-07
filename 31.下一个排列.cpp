/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
        {
            return;
        }

        int i = len - 1;
        int j = len - 1;
        for(; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                for(; j >= i; j--)
                {
                    if(nums[j] > nums[i - 1])
                    {
                        break;
                    }
                }
                nums[i - 1] = nums[i - 1] ^ nums[j];
                nums[j]     = nums[i - 1] ^ nums[j];
                nums[i - 1] = nums[i - 1] ^ nums[j];
                break;
            }
        }

        int start = i;
        int end = len - 1;
        int mid = (start + len) / 2;
        for(i = 0; i < mid - start; i++)
        {
            nums[start + i]   = nums[start + i] ^ nums[len - i - 1];
            nums[len - i - 1] = nums[start + i] ^ nums[len - i - 1];
            nums[start + i]   = nums[start + i] ^ nums[len - i - 1];
        }

        return;
    }
};
// @lc code=end

