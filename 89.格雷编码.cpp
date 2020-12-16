/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; i++) {
            int N = res.size();
            for (int j = 0; j < N; j++) {
                res.push_back(res[N-1-j] + (1 << i));
            }
        }
        return res;
    }
};
// @lc code=end

