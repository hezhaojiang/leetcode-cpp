/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
#ifdef DFS
    vector<int> item;
#endif
    vector<vector<int>> result;
public:
#ifdef DFS
    void dfs(int i, vector<int>& nums) {
        if (i == 0) return result.push_back(item);
        dfs(i - 1, nums);
        item.push_back(nums[i - 1]);
        dfs(i - 1, nums);
        return item.pop_back();
    }
#endif

    vector<vector<int>> subsets(vector<int>& nums) {
#ifdef DFS
        dfs(nums.size(), nums);
#endif
        result.push_back(vector<int>{});
        for (auto num : nums) {
            int count = result.size();
            for (int i = 0; i < count; i++) {
                result.push_back(result[i]);
                result[i + count].push_back(num);
            }
        }
        return result;
    }
};
// @lc code=end

