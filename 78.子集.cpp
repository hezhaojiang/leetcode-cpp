/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtracking(
        int i,
        vector<int>& nums,
        vector<int>& item,
        vector<vector<int>>& res
    )
    {
        if(0 != i)
        {
            item.push_back(nums[i - 1]);
            res.push_back(item);
            backtracking(i - 1, nums, item, res);
            item.pop_back();
            backtracking(i - 1, nums, item, res);
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> item;
        result.push_back(item);
        backtracking(nums.size(), nums, item, result);
        return result;
    }
};
// @lc code=end

