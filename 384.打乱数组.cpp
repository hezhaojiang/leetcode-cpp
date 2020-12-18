/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {
        va = nums;
        ra = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return va;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(ra.begin(), ra.end());
        return ra;
    }

private:
    vector<int> ra;
    vector<int> va;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

