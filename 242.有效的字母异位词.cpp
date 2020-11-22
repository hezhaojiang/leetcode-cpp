/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
#define _USE_SORT
    bool isAnagram(string s, string t) {
#ifdef _USE_HASH
        vector<int> letterNum(26, 0);
        for (auto c : s) letterNum[c - 'a']++;
        for (auto c : t) letterNum[c - 'a']--;
        for (auto n : letterNum) if (n != 0) return false;
        return true;
#endif
#ifdef _USE_SORT
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t ? true : false;
#endif
    }
};
// @lc code=end

