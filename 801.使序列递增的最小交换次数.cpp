/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        vector<int> keep(N, N);
        vector<int> swap(N, N);
        keep[0] = 0;
        swap[0] = 1;
        for (int i = 1; i < N; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                keep[i] = min(swap[i - 1], keep[i]);
                swap[i] = min(keep[i - 1] + 1, swap[i]);
            }
        }
        return min(keep.back(), swap.back());
    }
};
// @lc code=end

