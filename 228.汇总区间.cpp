/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int N = nums.size();
        int start = nums[0], end = start;
        vector<string> res;
        for (int i = 1; i <= N; i++) {
            if (i < N && end + 1 == nums[i]) end++;
            if (i == N || nums[i] != end) {
                if (start == end) res.push_back(to_string(start));
                else res.push_back(to_string(start) + "->" + to_string(end));
                if (i != N) start = end = nums[i];
            }
        }
        return res;
    }
};
// @lc code=end

