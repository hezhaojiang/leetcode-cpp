/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    static bool compare(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int m = intervals.size();
        vector<vector<int>> result;
        if (m == 0) return result;
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> value;
        for (auto & inter : intervals) {
            if (!value.empty()) {
                if (value[1] < inter[0]) {
                    result.push_back(value);
                    value = inter;
                }
                else value[1] = max(inter[1], value[1]);
            }
            else value = inter;
        }
        result.push_back(value);
        return result;
    }
};
// @lc code=end

