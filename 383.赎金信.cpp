/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26, 0);
        for (auto c : magazine) mp[c - 'a']++;
        for (auto c : ransomNote) mp[c - 'a']--;
        for (auto & m : mp) if (m < 0) return false;
        return true;
    }
};
// @lc code=end

