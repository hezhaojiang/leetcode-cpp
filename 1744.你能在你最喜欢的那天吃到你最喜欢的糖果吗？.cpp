/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 *
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */
#include <vector>
using namespace std;
// @lc code=start
using llint = long long int;
class Solution {
public:
    vector<bool> canEat(vector<int>& cand, vector<vector<int>>& que) {
        int n = cand.size();
        vector<llint> sum(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + cand[i];
        vector<bool> res;
        for (auto& q : que) {
            // 每天吃一颗都不够
            int type = q[0], day = q[1] + 1, cap = q[2];
            if (day > sum[type + 1]) res.push_back(false);
            // 每天吃很多都吃不到
            else if (1LL * day * cap <= sum[type]) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};
// @lc code=end
