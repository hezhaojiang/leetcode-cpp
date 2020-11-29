/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left == right) return 0;
        int mid = (left + right) / 2;
        int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        int ret = n1 + n2;

        // 首先统计下标对的数量
        for (int i = left, r = mid + 1, l = r; i <= mid; i++) {
            while (l <= right && sum[l] - sum[i] < lower) l++;
            while (r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
        }

        // 随后合并两个排序数组
        vector<int> sorted(right - left + 1);
        int m, n, p;
        for (m = left, n = mid + 1, p = 0; m <= mid && n <= right; p++) {
            if (sum[m] < sum[n]) sorted[p] = sum[m++];
            else sorted[p] = sum[n++];
        }
        while (m <= mid) sorted[p++] = sum[m++];
        while (n <= right) sorted[p++] = sum[n++];
        for (int i = 0; i < sorted.size(); i++) sum[left + i] = sorted[i];
        return ret;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        vector<long> preSum(1, 0);
        for (auto n : nums) preSum.push_back(preSum.back() + n);
        /************* Time Limit Exceeded *********************
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                long long diff = preSum[j + 1] - preSum[i];
                if (lower <= diff && diff <= upper) count++;
            }
        }
        return count;
        ********************************************************/
        return countRangeSumRecursive(preSum, lower, upper, 0, preSum.size() - 1);
    }
};
// @lc code=end
