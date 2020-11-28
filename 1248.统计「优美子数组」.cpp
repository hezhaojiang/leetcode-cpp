/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = 0;
        int oddcount = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto n : nums) {
            oddcount += (n % 2 != 0);
            if (mp.find(oddcount - k) != mp.end()) {
                result += mp[oddcount - k];
            }
            mp[oddcount]++;
        }
        return result;
    }
};
// @lc code=end

