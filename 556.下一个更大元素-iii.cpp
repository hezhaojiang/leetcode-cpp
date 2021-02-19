/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.length() < 2) return -1;
        int N = s.length();
        for (int i = N - 1; i > 0; i--) {
            if (s[i - 1] >= s[i]) continue;
            int j = N - 1;
            while (s[j] < s[i - 1]) j++;
            swap(s[i - 1], s[j]);
            long long res = stoll(s);
            if (res > INT_MAX) return -1;
            else return res;
        }
        return -1;
    }
};
// @lc code=end
