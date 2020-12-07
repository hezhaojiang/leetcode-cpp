/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        /* 行翻转 */
        int result = 0;
        int N = A.size();
        if (!N) return result;
        for (auto & line : A) if (line[0] == 0) for (auto & n : line) n = !n;
        for (int i = 0; i < A[0].size(); i++) {
            int oneCount = 0;
            for (int j = 0; j < N; j++) oneCount += A[j][i];
            oneCount = max(oneCount, N - oneCount);
            result += oneCount << A[0].size() - i - 1;
        }
        return result;
    }
};
// @lc code=end

