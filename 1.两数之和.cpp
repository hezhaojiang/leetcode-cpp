/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapIi;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mapIi.find(target - nums[i]) != mapIi.end())
                return vector<int>{i, mapIi[target - nums[i]]};
            if(mapIi.find(nums[i]) == mapIi.end()) 
                mapIi[nums[i]] = i;
        }
        return vector<int>{0, 0};
    }
};
// @lc code=end

