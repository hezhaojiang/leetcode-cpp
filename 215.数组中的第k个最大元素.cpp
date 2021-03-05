/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
#if 0
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
#endif
        std::priority_queue<int, std::vector<int>, std::greater<int> > small;
        for (int i = 0; i < nums.size(); i++) {
            if (small.size() < k) small.push(nums[i]);
            else if (nums[i] > small.top()) small.pop(), small.push(nums[i]);
        }
        return small.top();
    }
};
// @lc code=end
