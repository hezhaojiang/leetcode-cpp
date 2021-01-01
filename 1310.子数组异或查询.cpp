/*
 * @lc app=leetcode.cn id=1310 lang=cpp
 *
 * [1310] 子数组异或查询
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        int M = queries.size();
        vector<int> preOR(N + 1, 0);
        for (int i = 0; i < N; i++) preOR[i + 1] = preOR[i] ^ arr[i];
        vector<int> res(M, 0);
        for (int i = 0; i < M; i++) {
            res[i] = preOR[queries[i][1] + 1] ^ preOR[queries[i][0]];
        }
        return res;
    }
};
// @lc code=end

