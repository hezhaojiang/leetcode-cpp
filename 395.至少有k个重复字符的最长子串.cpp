/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() < k) return 0;
        // 统计 s 中每个字符出现的次数
        vector<int> count(26, 0);
        for (auto& c : s) count[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (0 < count[i] && count[i] < k) {
                char spilt = 'a' + i;
                vector<string> t;
                istringstream iss(s);
                string stmp;
                while (getline(iss, stmp, spilt)) t.push_back(stmp);
                int res = 0;
                for (string tn : t) res = max(res, longestSubstring(tn, k));
                return res;
            }
        }
        return s.length();
    }
};
// @lc code=end
