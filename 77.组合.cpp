/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtrack(int n, int k, vector<int>& item, vector<vector<int>>& result)
    {
        if(0 == k)
        {
            result.push_back(item);
            return;
        }
        if(n != 0)
        {
            item.push_back(n);
            backtrack(n - 1, k - 1, item, result);
            item.pop_back();
            backtrack(n - 1, k, item, result);
        }
        return;
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> item;
        backtrack(n, k, item, result);
        return result;
    }
};
// @lc code=end

