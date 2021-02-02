/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int N = A.size();
        int onecount = 0;
        int left = 0, right = 0;
        while (right < N) {
            onecount += A[right++] == 1;
            if (right - left - onecount > K) onecount -= A[left++] == 1;
        }
        return right - left;
    }
};
// @lc code=end

