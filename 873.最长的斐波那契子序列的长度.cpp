/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = arr.size();
        int res = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < N; i++) {
            mp[arr[i]] = i;
        }
        vector<vector<int>> dp(N, vector<int>(N, 2));
        for (int j = 1; j < N; j++) {
            for(int i = 0; i < j; i++) {
                int next = arr[i] + arr[j];
                if (mp.find(next) == mp.end()) continue;
                int index = mp[next];
                dp[j][index] = max(dp[j][index], dp[i][j] + 1);
                res = max(res, dp[j][index]);
            }
        }
        return res;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> arr{1,2,3,4,5,6,7,8};
    solve.lenLongestFibSubseq(arr);
    return 0;
}
