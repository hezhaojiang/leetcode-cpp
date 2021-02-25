/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    unordered_set<string> ans;  // 答案中可能会重复 需要去重
    // cnt 为当前左 - 右的值 l 为需要删除的左括号数量 r 为右
    void dfs(string &s, int u, string res, int cnt, int l, int r) {
        // cout << "\"" << res << "\"" << endl;
        if (u == s.size()) {
            if (!cnt) ans.insert(res);
            return;
        }
        if (s[u] == '(') {  // 在合法的条件下考虑删除
            int k = u;
            while (k < s.size() && s[k] == '(') k++;    // 找到最后一个连续的'('的右边
            l -= k - u;                                 // 假设将这些连续的'('全部删除
            for (int i = k - u; i >= 0; i--) {          // i为删除后的位置
                if (l >= 0) dfs(s, k, res, cnt, l, r);  // 可删时
                res += '(', cnt++, l++;
            }
        } else if (s[u] == ')') {  // 在合法的条件下考虑删除
            int k = u;
            while (k < s.size() && s[k] == ')') k++;                // 找到最后一个连续的'('的右边
            r -= k - u;                                             // 假设将这些连续的'('全部删除
            for (int i = k - u; i >= 0; i--) {                      // i为删除后的位置
                if (cnt >= 0 && r >= 0) dfs(s, k, res, cnt, l, r);  // 可删时
                res += ')', cnt--, r++;
            }
        } else
            dfs(s, u + 1, res + s[u], cnt, l, r);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        // 1. 先求出最少需要删除几个左括号和右括号
        int l = 0, r = 0;  // l 为当前左括号 - 右括号的值 r 为需要删掉的右括号的值
        for (auto v : s) {
            if (v == '(') l++;
            else if (v == ')') {
                if (l == 0) r++;  // 此时无效 右括号 必删
                else l--;         // 右括号 + 1 则左 - 右的值需要 - 1
            }
        }

        // 此时的 l 为需要删除的左括号数量 r 为需要删除的右括号数量
        dfs(s, 0, "", 0, l, r);
        return vector<string>(ans.begin(), ans.end());
    }
};
// @lc code=end
