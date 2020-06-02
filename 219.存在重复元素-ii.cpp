/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> numCount;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) numCount.erase(nums[i-k-1]);
            if(numCount.find(nums[i]) != numCount.end()) return true;
            numCount.insert(std::pair<int,int> (nums[i], 1));
        }
        return false;
    }
};
// @lc code=end

