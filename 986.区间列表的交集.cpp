/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        sort(firstList.begin(), firstList.end());
        sort(secondList.begin(), secondList.end());
        int i = 0, j = 0;
        int m = firstList.size(), n = secondList.size();
        while (i < m && j < n) {
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if (l <= r) res.push_back(vector<int>{l, r});
            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return res;
    }
};
// @lc code=end

