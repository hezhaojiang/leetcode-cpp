/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int N = A.size();
        int dp = 0;
        int res = 0;
        for (int i = 2; i < N; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) dp += 1;
            else dp = 0;
            res += dp;
        }
        return res;
    }
};
// @lc code=end

