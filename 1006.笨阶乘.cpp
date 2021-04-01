/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        int index = 0;
        vector<int> nums{N};
        while (--N) {
            if (index == 0) nums.back() *= N;
            else if (index == 1) nums.back() /= N;
            else if (index == 2) nums.push_back(N);
            else nums.push_back(-1 * N);
            if (++index == 4) index = 0;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end

