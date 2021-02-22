/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satis = 0, N = customers.size(), res = 0;
        vector<int> unsatis(N + 1, 0);
        for (int i = 0; i < N; i++) {
            unsatis[i + 1] = unsatis[i] + grumpy[i] * customers[i];
            if (!grumpy[i]) satis += customers[i];
        }
        for (int i = 0; i <= N - X; i++) {
            res = max(res, satis + unsatis[i + X] - unsatis[i]);
        }
        return res;
    }
};
// @lc code=end
