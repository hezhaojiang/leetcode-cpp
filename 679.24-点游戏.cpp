/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    static constexpr double EPSILON = 1e-4;
    bool dfs(vector<double>& l, double target) {
        if (l.size() == 0) return false;
        if (l.size() == 1) return fabs(l[0] - target) < EPSILON;
        int size = l.size();
        for (int i = 0; i < size; i++) {
            vector<double> c = l;
            c.erase(c.begin() + i);
            if (dfs(c, target - l[i]) || dfs(c, target + l[i])
                || dfs(c, l[i] - target) || dfs(c, target / l[i])
                || dfs(c, target * l[i]) || dfs(c, l[i] / target))
                return true;
            if (size <= 2) continue;
            for (int j = 0; j < size - 1; j++) {
                vector<double> d = c;
                d.erase(d.begin() + j);
                if (((fabs(l[i] - c[j])) > EPSILON && dfs(d, target / (l[i] - c[j]))) 
                    || ((fabs(l[i] + c[j])) > EPSILON && dfs(d, target / (l[i] + c[j])))
                    || ((fabs(l[i] - c[j])) > EPSILON && dfs(d, target / (c[j] - l[i])))
                    || ((fabs(l[i] + c[j])) > EPSILON && dfs(d, target * (l[i] + c[j])))
                    || ((fabs(l[i] - c[j])) > EPSILON && dfs(d, target * (c[j] - l[i])))
                    || ((fabs(l[i] - c[j])) > EPSILON && dfs(d, target * (l[i] - c[j]))))
                    return true;
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> l;
        for (const int &num : nums) {
            l.emplace_back(static_cast<double>(num));
        }
        return dfs(l, 24);
    }
};
// @lc code=end
int main() {
    Solution solve;
    solve.judgePoint24(vector<int>{1,2,1,2});
    return 0;
}
