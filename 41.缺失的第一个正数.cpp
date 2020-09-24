/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int N = nums.size();
        int i = 0;
        while (i < N) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else i++;
        }
        i = 0;
        while (i < N) 
            if (nums[i] != i + 1) return i + 1;
            else i++;
        return N + 1;
    }
};
// @lc code=end

