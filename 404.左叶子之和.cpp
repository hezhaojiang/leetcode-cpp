/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */
#include<iostream>
#include<queue>
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
#ifdef REVERSE
    int dfs(TreeNode* root, bool isleft) {
        if (!root) return 0;
        if (!root->left && !root->right && isleft) return root->val;
        return dfs(root->left, true) + dfs(root->right, false);
    }
#else
    bool inline isLeaf(TreeNode* root) {
        return root && !root->left && !root->right;
    }
#endif
public:
    int sumOfLeftLeaves(TreeNode* root) {
#ifdef REVERSE
        return dfs(root, false);
#else
        if (!root) return 0;
        queue<TreeNode*> Q;
        int result = 0;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            if (isLeaf(node->left)) result += node->left->val;
            else if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
        }
        return result;
#endif
    }
};
// @lc code=end

