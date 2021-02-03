/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char index[128] = {0};
        int N = s.length();
        int maxlen = 0;
        int start = 0, end = 0;
        while (end < N) {
            index[s[end]]++;
            while (index[s[end]] > 1) index[s[start++]]--;
            end++;
            maxlen = max(maxlen, end - start);
        }
        return maxlen;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    solve.lengthOfLongestSubstring("pwwkew");
    return 0;
}

