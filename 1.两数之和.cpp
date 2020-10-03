/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); i++) {
            if(M.find(target - nums[i]) != M.end()) return vector<int>{i, M[target - nums[i]]};
            M[nums[i]] = i;
        }
        return vector<int>{0, 0};
    }
};
// @lc code=end

