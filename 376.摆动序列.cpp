/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

#include <vector>

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return nums.size();
        }

        int dec = 0;
        int seglenth = 1;
        std::vector<int> decs;

        for(int i = 1; i < nums.size(); i++)
        {
            dec = nums[i] - nums[i - 1];
            if(dec != 0)
            decs.push_back(dec);
        }

        if(!decs.empty())
        {
            seglenth++;
        }

        for(int i = 1; i < decs.size(); i++)
        {
            if((decs[i] ^ decs[i - 1]) < 0)
            {
                seglenth++;
            }
        }
        return seglenth;
    }
};
// @lc code=end

