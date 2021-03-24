/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        vector<int> dp(5001, 0);  // dp[i] 两侧钢筋的高度差为 i 时的最大长度之和
        for (auto r : rods) {
            auto dp_tmp = dp;
            for (int i = 0; i < 5001; i++) {
                if (dp[i] < i) continue;
                // 放短边
                int l = abs(i - r);
                dp_tmp[l] = max(dp_tmp[l], dp[i] + r);
                // 放长边
                l = abs(i + r);
                dp_tmp[l] = max(dp_tmp[l], dp[i] + r);
            }
            swap(dp, dp_tmp);
        }
        return dp[0] / 2;
    }
};
// @lc code=end
