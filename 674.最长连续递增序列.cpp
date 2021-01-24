/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int N = nums.size();
        int maxlen = 1;
        int len = 1;
        for(int i = 1; i < N; i++) {
            if (nums[i] > nums[i - 1]) len++;
            if (i == N - 1 ||  nums[i] <= nums[i - 1]) {
                maxlen = max(maxlen, len);
                len = 1;
            }
        }
        return maxlen;
    }
};
// @lc code=end

