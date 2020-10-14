/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> re;
        vector<int> m1(26, 100);
        vector<int> m2(26, 0);
        for (auto & a : A) {
            for (auto c : a) m2[c - 'a']++;
            for (int i = 0; i < 26; i++) { m1[i] = min(m1[i], m2[i]); m2[i] = 0; }
        }
        for (int i = 0; i < 26; i++) while (m1[i]-- != 0) re.emplace_back(1, 'a' + i);
        return re;
    }
};
// @lc code=end

