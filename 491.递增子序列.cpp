/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
    vector<int> item;
    // 判重代码；
    bool is_first(const vector<int> &num, int pos, int last) {
        for(int i = last + 1; i < pos; i++) 
            if(num[i] == num[pos]) return false;
        return true;
    }
    void dfs(const vector<int>& nums, int begin, int last) {
        if (begin == nums.size()) return;
        if ((item.empty() || nums[begin] >= item.back()) && is_first(nums, begin, last)) {
            item.push_back(nums[begin]);
            if (item.size() >= 2) result.push_back(item);
            dfs(nums, begin + 1, begin);
            item.pop_back();
        }
        dfs(nums, begin + 1, last);
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0, -1);
        return result;
    }
};
// @lc code=end

