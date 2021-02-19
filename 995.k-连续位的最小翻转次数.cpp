/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N = A.size();
        int res = 0;
        int change = 0;
        vector<int> events(N, 0);
        int i = 0;
        for (i = 0; i < N - K + 1; i++) {
            if (A[i] == change) {
                res++;
                events[i + K - 1] = 1;
                change = !change;
            }
            if (events[i]) change = !change;
        }
        for (; i < N; i++) {
            if (A[i] == change) return -1;
            if (events[i]) change = !change;
        }
        return res;
    }
};
// @lc code=end
