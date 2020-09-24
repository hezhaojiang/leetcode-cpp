/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result;
        int M = A.size();
        if (M == 0) return A;
        int N = A[0].size();
        if (N == 0) return A;
        for (int i = 0; i < N; i++) {
            vector<int> item;
            for (int j = 0; j < M; j++) item.push_back(A[j][i]);
            result.push_back(item);
        }
        return result;
    }
};
// @lc code=end

