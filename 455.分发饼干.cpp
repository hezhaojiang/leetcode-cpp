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

        vector<int>::iterator iter_g = g.begin();
        vector<int>::iterator iter_s = s.begin();

        int satisfy = 0;

        while(iter_g != g.end() && iter_s != s.end())
        {
            if(*iter_g <= *iter_s)
            {
                iter_s++;
                satisfy++;
            }
            iter_g++;
        }
        return satisfy;
    }
};
// @lc code=end

