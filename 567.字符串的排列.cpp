/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int M = s1.size();
        int N = s2.size();
        int matchlength = 0, otherlength = 0;
        vector<int> nums(26, 0);
        for (auto c : s1) nums[c - 'a']--;
        int left = 0, right = 0;
        while (right < N) {
            nums[s2[right] - 'a']++;
            if (nums[s2[right] - 'a'] <= 0) matchlength++;
            else otherlength++;
            if (right++ >= M) {
                if (--nums[s2[left++] - 'a'] < 0) matchlength--;
                else otherlength--;
            }
            if (matchlength == M && otherlength == 0) return true;
        }
        return false;
    }
};
// @lc code=end

