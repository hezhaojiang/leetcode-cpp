/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        int n = A.size();
        for (int i = n - 1; i >= 0 || K > 0; --i, K /= 10) {
            if (i >= 0) K += A[i];
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

