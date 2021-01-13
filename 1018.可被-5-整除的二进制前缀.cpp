/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int num = 0;
        for (auto & a : A) {
            num = num * 2 + a;
            if (num % 5 == 0) res.push_back(true);
            else res.push_back(false);
            num %= 5;
        }
        return res;
    }
};
// @lc code=end

