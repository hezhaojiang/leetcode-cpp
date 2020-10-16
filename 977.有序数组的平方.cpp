/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        if (N == 0) return {};
        vector<int> B;
        int zero = 0;
        for (zero = 0; zero < N; zero++) if (A[zero] >= 0) break;
        int left = zero - 1;
        int right = zero;
        while (left >= 0 || right < N) {
            if (left < 0) B.push_back(pow(A[right++], 2));
            else if (right >= N) B.push_back(pow(A[left--], 2));
            else if (abs(A[left]) < abs(A[right])) B.push_back(pow(A[left--], 2));
            else B.push_back(pow(A[right++], 2));
        }
        return B;
    }
};
// @lc code=end

