/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> vs;
        for (auto n : nums) vs.push_back(to_string(n));
        sort(vs.begin(), vs.end(), 
            [] (string &a, string &b) {
                return a + b > b + a;
            });
        for (auto & a : vs) s += a;
        if (s[0] == '0') return "0";
        else return s;
    }
};
// @lc code=end

