/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
private:
    const int mod = 10000007;
    string res;
    bool check_twice(string &s, int a, int b, int len) { return s.substr(a, len) == s.substr(b, len); }
    bool isDupSubstring(string &s, int len) {
        int N = s.length();
        int l = 0, r = 0;
        int hashValue = 0;
        unordered_map<int, int> m;  // key : 哈希值 | value : 索引位置
        int often = 1;
        for (int i = 0; i < len; i++) often = (31 * often) % mod;
        while (r < N) {
            hashValue = (hashValue * 31 + (s[r++] - 'a')) % mod;
            if (r < len) continue;
            if (r - l > len) hashValue = (hashValue + mod - (s[l++] - 'a') * often) % mod;
            if (hashValue < 0) hashValue += mod;
            if (m.count(hashValue) && check_twice(s, l, m[hashValue], len)) {
                if (len > res.length()) res = s.substr(l, len);
                return true;
            } else m[hashValue] = l;
        }
        return false;
    }

public:
    string longestDupSubstring(string s) {
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (isDupSubstring(s, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return res;
    }
};
// @lc code=end
