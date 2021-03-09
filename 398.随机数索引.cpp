/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int>::iterator begin, end;

public:
    Solution(vector<int>& nums) {
        begin = nums.begin();
        end = nums.end();
    }

    int pick(int target) {
        int index = 0;
        int res = 0;
        for (auto it = begin; it != end; it++) {
            if (*it == target) {
                index++;
                if (rand() % index == 0) res = it - begin;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
