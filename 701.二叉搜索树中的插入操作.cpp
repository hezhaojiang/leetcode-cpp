/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */
struct TreeNode {
    int val;     TreeNode *left;
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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //if (!root) return new TreeNode(val);
        //if (root->val > val) root->left = insertIntoBST(root->left, val);
        //else if (root->val < val) root->right = insertIntoBST(root->right, val);

        if (!root) return new TreeNode(val);
        TreeNode *node = root, *prenode = nullptr;
        while (node) {
            prenode = node;
            if (node->val > val) node = node->left;
            else if (node->val < val) node = node->right;
        }
        if (prenode->val > val) prenode->left = new TreeNode(val);
        else if (prenode->val < val) prenode->right = new TreeNode(val);
        return root;
    }
};
// @lc code=end

