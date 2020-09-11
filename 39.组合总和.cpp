/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtrack(vector<int>& candidates, int k, int target, int val,
        vector<int>& item, vector<vector<int>>& result) {
        if(val == target) return result.push_back(item);
        if(candidates.size() == k) return;

        int index = 0;
        while(val <= target) {
            backtrack(candidates, k + 1, target, val, item, result);
            item.push_back(candidates[k]);
            val = val + candidates[k];
            index++;
        }
        while(index--) item.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> item;
        int curVal = 0;
        backtrack(candidates, 0, target, curVal, item, result);
        return result;
    }
};
// @lc code=end

