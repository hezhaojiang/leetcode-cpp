/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    vector<vector<bool>> ispalindrome;
    vector<vector<string>> res;
    vector<string> splite;
    void checkpalindrome(string& s, int l, int r) {
        while (l >= 0 && r < s.length()) {
            if (s[l] == s[r]) ispalindrome[l--][r++] = true;
            else return;
        }
    }
    void dfs(string& s, int l) {
        if (l == s.length()) {
            res.push_back(splite);
            return;
        }
        for (int r = l; r < s.length(); r++) {
            if (ispalindrome[l][r]) {
                splite.push_back(s.substr(l, r - l + 1));
                dfs(s, r + 1);
                splite.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        ispalindrome.resize(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            checkpalindrome(s, i, i);
            checkpalindrome(s, i, i + 1);
        }
        vector<int> splite;
        dfs(s, 0);
        return res;
    }
};
// @lc code=end
