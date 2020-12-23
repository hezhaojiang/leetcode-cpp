/*
 * @lc app=leetcode.cn id=871 lang=cpp
 *
 * [871] 最低加油次数
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int N = stations.size();
        vector<long long> dp(N + 1, 0); //加了 i 次油后能走的总距离
        dp[0] = startFuel;
        int start = 0;
        //sort(stations.begin(), stations.end());
        for (int i = 0; i < N; i++) {
            for (int t = i; t >= 0; t--) {
                if (dp[t] >= stations[i][0]) 
                    dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
            }
        }
        for (int i = 0; i <= N; ++i) if (dp[i] >= target) return i;
        return -1;
    }
};
// @lc code=end

