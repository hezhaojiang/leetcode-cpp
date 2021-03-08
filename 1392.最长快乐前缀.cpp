/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 *
 * [1392] 最长快乐前缀
 */
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPrefix(string s) {
        // KMP 算法 Next 数组求法
        int n = s.length();
        vector<int> next(n + 1, -1);
        int i = 0, j = -1;
        while (i < n) {
            if (j == -1 || s[i] == s[j]) next[++i] = ++j;
            else j = next[j];
        }
        return s.substr(0, next[s.length()]);
    }
};
// @lc code=end
