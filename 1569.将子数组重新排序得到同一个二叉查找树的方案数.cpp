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
    const int mod = 1000000007;
    vector<vector<int>> nCK;
    long long int dfs(vector<int>& nums) {
        vector<int> a, b;
        int n = nums.size();
        if (n <= 2) return 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) a.push_back(nums[i]);
            else if (nums[i] > nums[0]) b.push_back(nums[i]);
        }
        
        long long comb = nCK[n - 1][a.size()];
        long long cont = (dfs(a) * dfs(b)) % mod;;
        return (comb * cont) % mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int size = nums.size();
        nCK.resize(size, vector<int>(size, 0));
        nCK[0][0] = 1;
        for (int i = 1; i < size; ++i) {
            nCK[i][0] = 1;
            for (int j = 1; j <= i; ++j)
                nCK[i][j] = (nCK[i - 1][j - 1] + nCK[i - 1][j]) % mod;
        }
        int res = dfs(nums);
        return res - 1;
    }
};
// @lc code=end

