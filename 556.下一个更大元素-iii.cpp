/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.length() == 1) return -1;
        int len = s.length();
        int l = len - 1, r = len - 1;
        while (l >= 0 && s[l] >= s[l + 1]) l--;
        if (l == -1) return -1;
        while (s[r] <= s[l]) r--;
        swap(s[l], s[r]);
        sort(s.begin() + l + 1, s.end());
        long long res = stoll(s);
        if (res > INT_MAX) return -1;
        else return res;
    }
};
// @lc code=end
