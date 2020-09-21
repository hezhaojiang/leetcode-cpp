/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */
#include<iostream>
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
private:
    int preSum;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->right);
        root->val = (preSum += root->val);
        dfs(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        preSum = 0;
        dfs(root);
        return root;
    }
};
// @lc code=end

