/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();
        if (n < 2) return ret;
#if 0
        int exp = 1;
        vector<int> buf(n);
        int maxVal = *max_element(nums.begin(), nums.end());

        while (maxVal >= exp) {
            vector<int> cnt(10);
            /* 首先根据个位数的数值，在走访数值时将它们分配至编号 0 到 9 的桶子中 */
            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            /* 将这些桶子中的数值重新串接起来 */
            for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                buf[cnt[digit]-- - 1] = nums[i];
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int ret = 0;
        for (int i = 1; i < n; i++) ret = max(ret, nums[i] - nums[i - 1]);
#endif
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxVal - minVal) / (n - 1)); /* 最大间距一定大于该值 */
        int bucketSize = (maxVal - minVal) / d + 1;  /* 根据差值 d 设置桶的个数 */

        vector<pair<int, int>> bucket(bucketSize, {-1, -1});  // 桶内最小值，桶内最大值，(-1, -1) 表示该桶是空的
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / d;
            if (bucket[idx].first == -1) bucket[idx].first = bucket[idx].second = nums[i];
            else {
                bucket[idx].first = min(bucket[idx].first, nums[i]);
                bucket[idx].second = max(bucket[idx].second, nums[i]);
            }
        }

        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) ret = max(ret, bucket[i].first - bucket[prev].second);
            prev = i;
        }
        return ret;
    }
};
// @lc code=end

