/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> sum;

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        sum.resize(triangle.size());
        for (auto line : triangle) {
            int last = 0;
            for (int i = 0; i < line.size(); i++) {
                int temp = sum[i];
                if (i == 0) sum[i] = sum[i] + line[i];
                else if (i == line.size() - 1) sum[i] = last + line[i];
                else sum[i] = min(sum[i], last) + line[i];
                last = temp;
            }
        }
        int minRes = INT_MAX;
        for (auto a : sum)
            if (a < minRes) minRes = a;
        return minRes;
    }
};
// @lc code=end
