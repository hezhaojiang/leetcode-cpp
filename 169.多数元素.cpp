/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int selct = 0;
        for (auto num : nums) {
            if (count == 0) selct = num;
            if (num == selct) count++;
            else count--;
        }
        return selct;
    }
};
// @lc code=end

