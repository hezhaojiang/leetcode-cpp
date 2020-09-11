/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> item;
    vector<vector<int>> result;
public:
    void backtrack(vector<int>& candidates, int k, int target, int val, vector<vector<int>>& result) {
        if(val == target) return result.push_back(item);
        if(candidates.size() == k) return;

        int index = 1;
        if (val <= target) {
            item.push_back(candidates[k]);
            while(candidates.size() - 1 != k && candidates[k] == candidates[k + 1]) {
                index++;
                item.push_back(candidates[k++]);
            }
            while (index) {
                backtrack(candidates, k + 1, target, val + index * candidates[k], result);
                item.pop_back();
                index--;
            }
            backtrack(candidates, k + 1, target, val, result);
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> item;
        int curVal = 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target, curVal, result);
        return result;
    }
};
// @lc code=end
int main() {
    Solution solve;
    vector<int> candidates;
    candidates.push_back(1);
    solve.combinationSum2(candidates, 1);
    return 0;
}

