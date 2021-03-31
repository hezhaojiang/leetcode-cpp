/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;

public:
    void backtracking(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& res) {
        int index = 1;
        if (0 <= i) {
            while (0 != i && nums[i - 1] == nums[i]) {
                item.push_back(nums[i--]);
                index++;
            }
            item.push_back(nums[i]);
            backtracking(i - 1, nums, item, res);
            while (index--) {
                res.push_back(item);
                item.pop_back();
                backtracking(i - 1, nums, item, res);
            }
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> item;
        result.push_back(item);
        backtracking(nums.size() - 1, nums, item, result);
        return result;
    }
};
// @lc code=end
