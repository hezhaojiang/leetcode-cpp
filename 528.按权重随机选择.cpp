/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */
#include <random>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> sum;

public:
    Solution(vector<int>& w) {
        int n = w.size();
        sum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + w[i];
    }

    int pickIndex() {
        int t = rand() % sum.back();
        auto it = upper_bound(sum.begin(), sum.end(), t);
        return it - sum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
