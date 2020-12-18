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
        int maxlen = 0;
        for(int start = 0, end = 0; end < s.length(); end++) {
            if(index[s[end]]++ == 0) maxlen = max(maxlen, end - start + 1);
            else {
                while (s[start] != s[end]) index[s[start++]]--;
                index[s[start++]]--;
            } 
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

