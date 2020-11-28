/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int result = 0;
        /************* Time Limit Exceeded *********************
        vector<long long> preSum(1, 0);
        for (auto n : A) preSum.push_back(preSum.back() + n);
        for (int i = 0; i < A.size(); i++) {
            for (int j = i; j < A.size(); j++) {
                long long dif = preSum[j + 1] - preSum[i];
                if (dif % K == 0) result++;
            }
        }
        ********************************************************/
        int rest = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto n : A) {
            rest = ((rest + n) % K + K) % K; // 排除余数是负数
            if (mp.find(rest) != mp.end()) result += mp[rest];
            mp[rest]++;
        }
        return result;
    }
};
// @lc code=end

