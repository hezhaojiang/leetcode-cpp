/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end(), std::greater<int>());
        std::sort(s.begin(), s.end(), std::greater<int>());
        int satisfy = 0;

        for (auto iter_g = g.begin(), iter_s = s.begin(); iter_g != g.end() && iter_s != s.end(); iter_g++) {
            if (*iter_g <= *iter_s) {
                iter_s++;
                satisfy++;
            }
        }
        return satisfy;
    }
};
// @lc code=end

