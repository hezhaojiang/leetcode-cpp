/*
 * @lc app=leetcode.cn id=1316 lang=cpp
 *
 * [1316] 不同的循环子字符串
 */
#include <algorithm>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int i, len, n = text.size(), count = 0;
        string_view t(text);
        for (len = 1; len <= n / 2 + 1; len++) {
            set<string_view> set;
            for (i = 0; i <= n - 2 * len; ++i) {
                if (t.substr(i, len) == t.substr(i + len, len)) set.insert(t.substr(i, len));
            }
            count += set.size();
        }
        return count;
    }
};
// @lc code=end
