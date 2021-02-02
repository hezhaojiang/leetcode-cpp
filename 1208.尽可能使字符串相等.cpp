/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        int need = 0;
        int left = 0, right = 0;
        while (right < N) {
            need += abs(s[right] - t[right]);
            right++;
            if (need > maxCost) {
                need -= abs(s[left] - t[left]);
                left++;
            }
        }
        return right - left;
    }
};
// @lc code=end

