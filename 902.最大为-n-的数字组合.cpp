/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    set<int> se;
    vector<int> nu;
    vector<vector<int>> dp;
    int getdp(int cur, int lim) {
        if (cur == -1) return 1;
        int& ans = dp[cur][lim];
        if (ans != -1) return ans;
        ans = 0;
        int up = lim ? nu[cur] : 9;
        for (int i : se) {
            if (i > up) break;
            ans += getdp(cur - 1, lim && (i == up));
        }
        return ans;
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int N) {
        for (auto s : digits) se.insert(stoi(s));
        while (N) {
            nu.push_back(N % 10);
            N /= 10;
        }
        dp.assign(nu.size(), vector<int>(2, -1));
        int n = nu.size();
        int res = getdp(nu.size() - 1, 1);
        for (int i = 1; i < n; i++) {
            res += getdp(i - 1, 0);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<string> digits{"1", "3", "5", "7"};
    solve.atMostNGivenDigitSet(digits, 100);
    return 0;
}
