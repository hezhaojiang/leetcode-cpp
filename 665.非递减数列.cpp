/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size();
        int change = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                change++;
                if (i > 1 && nums[i - 2] > nums[i]
                    && i < N - 1 && nums[i + 1] < nums[i - 1]) change++;
            }
            if (change > 1) return false;
        }
        return true;
    }
};
// @lc code=end

