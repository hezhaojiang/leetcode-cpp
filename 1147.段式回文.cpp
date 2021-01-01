/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        int res = 0;
        int prev = 0;
        int S = text.size();
        for (int i = 0; i < S / 2; i++) {
            if ((text.substr(prev, i - prev + 1)) == text.substr(S - 1 - i, i - prev + 1)) {
                res += 2;
                prev = i + 1;
            }
        }
        if (S % 2 == 1 || prev < S / 2) res++;
        return res;
    }
};
// @lc code=end

