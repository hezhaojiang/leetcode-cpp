/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int res = 0;
    vector<int> arrmask;
    void dfs(int u, int s) {
        res = max(res, __builtin_popcount(s));
        if (u == arrmask.size()) return;
        for (int i = u; i < arrmask.size(); i++) {
            if ((s & arrmask[i]) != 0) continue;
            dfs(i + 1, s | arrmask[i]);
        }
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (auto c : arr[i]) {
                if (mask & 0x1 << (c - 'a')) {
                    mask = 0;
                    break;
                }
                mask |= 0x1 << (c - 'a');
            }
            if (mask) arrmask.push_back(mask);
        }
        dfs(0, 0);
        return res;
    }
};
// @lc code=end
