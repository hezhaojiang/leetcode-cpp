/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int last = INT_MIN;
        int n = nums.size();
        for (int i = n - 1; i > -1; i--) {
            if (nums[i] < last) return true;
            if (stk.empty() || nums[i] < stk.top()) stk.push(nums[i]);
            else if (nums[i] > stk.top()) {
                while (!stk.empty() && nums[i] > stk.top()) last = stk.top(), stk.pop();
                stk.push(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end
