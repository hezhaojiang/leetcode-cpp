/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
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
    void dfs(vector<int>& nums) {
        if (item.size() == nums.size()) {
            result.push_back(item);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int tag = 0;
            if (0 != flag[i]) {
                /* 题目可以理解为 ：重复数字的排列顺序不能修改
                 * 比如 131 将第一位和第三位的 1 调换位置，仍为 131
                 * 即重复的数字应按顺序加入到 item 数组中
                 * 如果查找在当前位置之前，有与当前数字重复的数字但却没有加入到 item 数组中，
                 * 则代表这个排列会打乱重复数字的排列，此时应该跳过该排列 */
                for (int j = 0; j < i; j++)
                    if(nums[i] == nums[j] && flag[j] != 0) {
                        tag = 1;
                        break;
                    }
                if (tag == 1) continue;
                item.push_back(nums[i]);
                flag[i] = 0;
                dfs(nums);
                flag[i] = 1;
                item.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) flag.push_back(1);
        dfs(nums);
        return result;
    }
};
// @lc code=end

