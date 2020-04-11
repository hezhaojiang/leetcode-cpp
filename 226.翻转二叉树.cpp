/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Reverse(TreeNode* root)
    {
        if(!root) return;
        TreeNode* temp;
        temp = root->right;
        root->right = root->left;
        root->left = temp;
        Reverse(root->left);
        Reverse(root->right);
        return;
    }
    TreeNode* invertTree(TreeNode* root) {
        Reverse(root);
        return root;
    }
};
// @lc code=end

