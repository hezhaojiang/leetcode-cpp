/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> nums(128, 0);
        for (char &c : t) --nums[c];
        int left = 0, right = 0;
        int N = s.size(), needletter = t.size();
        int len = INT_MAX, start = 0;
        while (right < N) {
            if (nums[s[right++]]++ < 0) needletter--;
            while (!needletter) {
                if (right - left < len) len = right - (start = left);
                if (--nums[s[left++]] < 0) ++needletter;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

