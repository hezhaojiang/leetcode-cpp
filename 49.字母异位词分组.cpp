/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapSvs;
        for (auto& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            mapSvs[s].emplace_back(str);
        }
        for (auto& ss : mapSvs) result.emplace_back(ss.second);
        return result;
    }
};
// @lc code=end

