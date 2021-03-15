/*
 * @lc app=leetcode.cn id=1467 lang=cpp
 *
 * [1467] 两个盒子中球的颜色数相同的概率
 */
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<double> dp;
    double nCK(int a, int b) { return dp[a] / dp[b] / dp[a - b]; }
    double dfs(vector<int>& balls, int i, int count1, int count2, int sum1, int sum2) {
        if (i == balls.size()) return sum1 == sum2 && count1 == count2;
        double res = 0;
        // 一共 balls[i] 个球 其中 box1 装 x 个 box2 装 y 个
        for (int x = 0; x <= balls[i]; x++) {
            int y = balls[i] - x;
            res += nCK(balls[i], x) *
                dfs(balls, i + 1, count1 + (x != 0), count2 + (y != 0), sum1 + x, sum2 + y);
        }
        return res;
    }

public:
    double getProbability(vector<int>& balls) {
        dp.resize(50, 1);
        for (int i = 2; i < 50; i++) dp[i] = dp[i - 1] * i;
        int ballCount = accumulate(balls.begin(), balls.end(), 0);
        double total = nCK(ballCount, ballCount >> 1);
        double valid = dfs(balls, 0, 0, 0, 0, 0);
        return valid / total;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> balls{1, 1};
    solve.getProbability(balls);
    return 0;
}
