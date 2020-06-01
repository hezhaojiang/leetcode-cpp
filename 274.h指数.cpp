/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H指数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int siz = citations.size();
        vector<int> cimap(siz, 0);
        for(auto a : citations)
            if(0 != a) cimap[min(a - 1, siz - 1)]++;
        int sumci = 0;
        for(int i = siz - 1; i >= 0; i--)
        {
            sumci += cimap[i];
            if(sumci > i) return i + 1;
        }
        return 0;
    }
};
// @lc code=end

