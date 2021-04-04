/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    int result = 0x80000000;
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        //计算左边分支最大值，左边分支如果为负数还不如不选择
        int leftPathSum = max(0, dfs(root->left));
        //计算右边分支最大值，右边分支如果为负数还不如不选择
        int rightPathSum = max(0, dfs(root->right));
        //left->root->right 作为路径与历史最大值做比较
        result = max(result, leftPathSum + rightPathSum + root->val);
        // 返回经过root的单边最大分支给上游
        return root->val + max(leftPathSum, rightPathSum);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return result;
    }
};
// @lc code=end

