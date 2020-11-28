/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int length = 0;
        if (nums.empty()) return 0;
        /************* Time Limit Exceeded *********************
        vector<long long> preSum(1, 0);
        for (auto n : nums) preSum.push_back(preSum.back() + n);
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j += 2) {
                if ((j - i + 1) / 2 == preSum[j + 1] - preSum[i])
                    length = max(j - i + 1, length);
            }
        }
        ********************************************************/
        int s = 0;
        unordered_map<int, int> preSum;
        preSum[0] = -1;
        for (int i = 0; i <nums.size(); i++) {
            s += nums[i] == 1 ? 1 : -1; /* s 用来指示前缀中 1 和 0 的个数差 */
            if (preSum.find(s) != preSum.end()) {
                length = max(length, i - preSum[s]);
            } else preSum[s] = i;
        }
        return length;
    }
};
// @lc code=end

