/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */
#include<vector>
#include<set>
using namespace std;
// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> stype;
        for (auto& c : candyType) stype.insert(c);
        return min(candyType.size() / 2, stype.size());
    }
};
// @lc code=end

