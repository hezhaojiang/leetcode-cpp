/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> base;
        while (numRows--) {
            vector<int> index(1,1);
            for (int i = 0; i + 1 < base.size(); i++) {
                index.push_back(base[i] + base[i + 1]);
            }
            if (base.size() != 0) index.push_back(1);
            base = index;
            result.push_back(base);
        }
        return result;
    }
};
// @lc code=end

