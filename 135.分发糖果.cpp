/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        /* 左规则 */
        vector<int> left(N, 0);
        for (int i = 0; i < N; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
            else left[i] = 1;
        }
        /* 右规则 */
        vector<int> right(N, 0);
        for (int i = N - 1; i >= 0; i--) {
            if (i < N - 1 && ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            else right[i] = 1;
        }

        int res = 0;
        for (int i = 0; i < N; i++) res += max(left[i], right[i]);
        return res;
    }
};
// @lc code=end

