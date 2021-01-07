/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int count = 0;
        for (int start = 0; count < len; start++) {
            int cur = start;
            int pre = nums[start];
            do {
                int target = (cur + k) % len;
                int temp = nums[target];
                nums[target] = pre;
                pre = temp;
                cur = target;
                count++;
            } while (cur != start);
        }
        return;
    }
};
// @lc code=end

