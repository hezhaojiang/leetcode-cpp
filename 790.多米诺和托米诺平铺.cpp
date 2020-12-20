/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
 */
#include<vector>
using namespace std;
// @lc code=start
#define MOD 1000000007
#define LL long long
class Solution {
public:
    int numTilings(int N) {
        vector<LL> full(N + 1);
        vector<LL> half(N + 1);
        full[0] = 1;
        half[0] = 0;
        full[1] = 1;
        half[1] = 0;
        for (int i = 2; i <= N; i++) {
            full[i] = (full[i - 1] + half[i - 1] + full[i - 2]) % MOD;
            half[i] = (2 * full[i - 2] + half[i - 1]) % MOD;
        }
        return full[N];
    }
};
// @lc code=end

