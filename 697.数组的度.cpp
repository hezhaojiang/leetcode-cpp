/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> count(50000, 0);
        int N = nums.size();
        for (int i = 0; i < N; i++) count[nums[i]]++;
        int maxdegree = *max_element(count.begin(), count.end());
        for (auto& c : count) c = 0;
        int l = 0, r = 0, res = N;
        while (r < N) {
            count[nums[r]]++;
            if (count[nums[r]] == maxdegree) {
                while (nums[l] != nums[r]) count[nums[l++]]--;
                res = min(res, r - l + 1);
                count[nums[l++]]--;
            }
            r++;
        }
        return res;
    }
};
// @lc code=end
