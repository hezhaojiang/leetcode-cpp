/*
 * @lc app=leetcode.cn id=1569 lang=cpp
 *
 * [1569] 将子数组重新排序得到同一个二叉查找树的方案数
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    int MOD = 1000000007;
    vector<vector<int>> C;
    long long int dfs(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        if (nums.size() <= 2) return 1;

        int first = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < first) a.push_back(nums[i]);
            else if (nums[i] > first) b.push_back(nums[i]);
        }
        
        long long int t = C[a.size() + b.size()][a.size()];
        long long al = dfs(a);
        long long bl = dfs(b);
        return (((t * al) % MOD) * bl) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int size = nums.size();
        C.resize(size, vector<int>(size, 0));
        C[0][0] = 1;
        for (int i = 1; i < size; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        int res = dfs(nums);
        return res - 1;
    }
};
// @lc code=end

