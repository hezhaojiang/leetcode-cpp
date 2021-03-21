/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode *dfs(vector<int> &nums, int l, int r) {
        if (l == r) return nullptr;
        auto index = max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
        TreeNode *node = new TreeNode(nums[index]);
        node->left = dfs(nums, l, index);
        node->right = dfs(nums, index + 1, r);
        return node;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        int n = nums.size();
        return dfs(nums, 0, n); // 左闭右开
    }
};
// @lc code=end
