/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int L = 0, N = nums.size();
        if (N <= 0) return -1; 
        vector<int> result(N, 0);
        for (int i = N - 2; i >= 0; --i) result[i] = result[i + 1] + nums[i + 1];
        if (result[0] == 0) return 0;
        for (int i = 1; i < N; ++i) {
            L += nums[i - 1];
            if (result[i] == L) return i;
        }
        return -1;
    }
};
// @lc code=end

