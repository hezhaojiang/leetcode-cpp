/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        vector<int> zero(32, 0);
        vector<int> one(32, 0);
        for (auto n : nums) {
            for (int i = 0; i < 32; i++) {
                if (n & (1 << i)) one[i]++;
                else zero[i]++;
            }
        }
        for (int i = 0; i < 32; i++) res += one[i] * zero[i];
#if 0
        for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) {
            res += __builtin_popcount(nums[i] ^ nums[j]);
        }
#endif
        return res;
    }
};
// @lc code=end
