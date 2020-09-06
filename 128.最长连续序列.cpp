/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<int, int> next;
    int getMaxnext(int n) {
        if (next.find(n) == next.end()) return n;
        else return next[n] = getMaxnext(next[n]);
    }
    int longestConsecutive(vector<int>& nums) {
        for (auto n : nums) next[n] = n + 1;
        int ans = 0;
        for (auto n : nums) ans = max(ans, getMaxnext(n) - n);
        return ans;
    }
};
// @lc code=end

