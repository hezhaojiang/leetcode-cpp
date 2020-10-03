/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
int kadane(vector<int>& A, int i, int j, int sign) {
        // The maximum non-empty subarray for array
        // [sign * A[i], sign * A[i+1], ..., sign * A[j]]
        int ans = -30000;
        int cur = -30000;
        for (int k = i; k <= j; ++k) {
            cur = sign * A[k] + max(cur, 0);
            ans = max(ans, cur);
        }
        return ans;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int S = 0;  // S = sum(A)
        for (int x : A) S += x;

        int ans1 = kadane(A, 0, A.size() - 1, 1);
        int ans2 = S + kadane(A, 1, A.size() - 1, -1);
        int ans3 = S + kadane(A, 0, A.size() - 2, -1);
        return max(ans1, max(ans2, ans3));
    }
};
// @lc code=end

