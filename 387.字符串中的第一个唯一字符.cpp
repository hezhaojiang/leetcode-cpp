/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, pair<int, int>> M;  //出现的位置和次数
        for (int i = 0; i < s.length(); i++) {
            if (M.find(s[i]) != M.end()) M[s[i]].second++;
            else M[s[i]] = {i, 1};
        }
        int index = s.length();
        for (auto & m : M) if (m.second.second == 1) index = min(m.second.first, index);
        return index == s.length() ? -1 : index;
    }
};
// @lc code=end

