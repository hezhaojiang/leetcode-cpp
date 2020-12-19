/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> num(26, 0);
        vector<int> vis(26, 0);
        for (auto c : s) num[c - 'a']++;
        string stk;
        for (auto c : s) {
            if (vis[c - 'a'] == 0) {
                while (!stk.empty() && c < stk.back()) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    }
                    else break;
                }
                stk.push_back(c);
                vis[stk.back() - 'a']++;
            }
            num[c - 'a']--;
        }
        return stk;
    }
};
// @lc code=end

