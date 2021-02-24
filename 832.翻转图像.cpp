/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& a : A) {
            reverse(a.begin(), a.end());
            for (auto& i : a) i = i ^ 1;
        }
        return A;
    }
};
// @lc code=end

