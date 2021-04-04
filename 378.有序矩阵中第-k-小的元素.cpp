/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> rec;
        for (auto& row : matrix) {
            for (int it : row) rec.push_back(it);
        }
        sort(rec.begin(), rec.end());
        return rec[k - 1];
    }
};

// @lc code=end
