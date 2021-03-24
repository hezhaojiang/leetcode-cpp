/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    vector<int> res;
    vector<int> index;
    vector<int> indexc;
    void mergeAndCount(vector<int>& nums, int l, int r) {
        if (l == r) return;
        // 1. 分
        int mid = l + r >> 1;
        mergeAndCount(nums, l, mid);
        mergeAndCount(nums, mid + 1, r);
        // 2. 治
        for (int i = l; i <= r; i++) indexc[i] = index[i];
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (nums[indexc[i]] <= nums[indexc[j]]) res[indexc[i]] += j - mid - 1, index[k++] = indexc[i++];
            else index[k++] = indexc[j++];
        }
        while (i <= mid) res[indexc[i]] += j - mid - 1, index[k++] = indexc[i++];
        while (j <= r) index[k++] = indexc[j++];
        return;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        index.assign(n, 0);
        res.assign(n, 0);
        for (int i = 0; i < n; i++) index[i] = i;
        indexc.assign(index.begin(), index.end());
        mergeAndCount(nums, 0, n - 1);
        return res;
    }
};
// @lc code=end
