/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
    vector<int> flag;
    vector<int> item;
    vector<vector<int>> result;
public:
    void backtracking(vector<int>& nums)
    {
        if(item.size() == nums.size())
        {
            result.push_back(item);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(0 != flag[i])
            {
                item.push_back(nums[i]);
                flag[i] = 0;
                backtracking(nums);
                flag[i] = 1;
                item.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            flag.push_back(1);
        }
        backtracking(nums);
        return result;
    }
};
// @lc code=end

