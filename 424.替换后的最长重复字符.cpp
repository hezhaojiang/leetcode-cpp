/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int N = s.size();
        vector<int> count(26, 0);
        int maxcount = 0;
        for (int left = 0, right = 0; right < N; right++) {
            count[s[right] - 'A']++;
            maxcount = max(maxcount, count[s[right] - 'A']);
            int rest = right - left + 1 - maxcount;
            if (rest <= k) res = max(res, right - left + 1);
            else count[s[left++] - 'A']--;
        }
        return res;
    }
};
// @lc code=end

