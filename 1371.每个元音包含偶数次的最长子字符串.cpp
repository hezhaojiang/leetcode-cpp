/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
#define IS_AEIOU(c) ( (c) == 'a' | ((c) == 'e') << 1 \
    | ((c) == 'i') << 2 | ((c) == 'o') << 3 | ((c) == 'u') << 4 )
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int N = s.length();
        int dif = 0;
        int length = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < N; i++) {
            dif ^= IS_AEIOU(s[i]);
            if (mp.find(dif) != mp.end()) {
                length = max(length, i - mp[dif]);
            } else mp[dif] = i;
        }
        return length;
    }
};
// @lc code=end

