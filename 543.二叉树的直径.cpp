/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
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
    int diameter;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        diameter = max(diameter, leftdepth + rightdepth);
        return max(leftdepth, rightdepth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }
};
// @lc code=end

