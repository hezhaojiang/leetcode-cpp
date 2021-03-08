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
    const int x = 31;
    const int mod = 10000019;
    vector<int> p;

public:
    int covfun(int a, int p) {
        if (a == 0 || a == 1) return 1;
        return 1ll * (p - p / a) * covfun(p % a, p) % p;
    }

    string longestPrefix(string s) {
        // 题解是从小到大 我试试从大到小
        int n = s.length();

        // 先求整个字符串的哈希值
        int shash = 0, len = n;
        for (auto& c : s) shash = (shash * 31 + c - 'a') % mod;

        const int cov = covfun(x, mod);
        int lhash = shash, rhash = shash;
        p.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * x) % mod;
        while (--len) {
            lhash = (1LL * ((lhash - s[len] + 'a' + mod) % mod) * cov) % mod;
            rhash = ((rhash - p[len] * (s[n - len - 1] - 'a')) % mod + mod) % mod;
            // 这里建议加上哈希冲突检测
            if (lhash == rhash) return s.substr(0, len);
        }
        return "";
    }
};
// @lc code=end
