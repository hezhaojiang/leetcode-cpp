/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        /************* Time Limit Exceeded *********************
        vector<long long> preSum(1, 0);
        for (auto n : nums) preSum.push_back(preSum.back() + n);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (k == preSum[j + 1] - preSum[i]) count++;
            }
        }
        ********************************************************/
        long long s = 0;
        unordered_map<long long, int> preSum;
        preSum[0] = 1;
        for (auto n : nums) {
            s += n;
            if (preSum.find(s - k) != preSum.end()) count += preSum[s - k];
            preSum[s]++;
        }
        return count;
    }
};
// @lc code=end

