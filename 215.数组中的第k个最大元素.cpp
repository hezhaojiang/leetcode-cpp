/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<vector>
#include<queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap;
        for(int i = 0; i < nums.size(); i++)
        {
            if(small_heap.size() < k)
            {
                small_heap.push(nums[i]);
            }
            else if(nums[i] >= small_heap.top())
            {
                small_heap.pop();
                small_heap.push(nums[i]);
            }
        }
        return small_heap.top();
    }
};
// @lc code=end

