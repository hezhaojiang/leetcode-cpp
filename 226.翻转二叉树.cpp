/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */
#include<vector>
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
public:
    TreeNode* invertTree(TreeNode* root) {
#ifdef REVERSE
        if (root) {
            swap(root->right, root->left);
            invertTree(root->left);
            invertTree(root->right);
        }
#else
        queue<TreeNode*> Q;
        if (!root) return root;
        Q.push(root);
        while (!Q.empty()) {
            TreeNode* T = Q.front();
            swap(T->right, T->left);
            if (T->left) Q.push(T->left);
            if (T->right) Q.push(T->right);
            Q.pop();
        }
#endif
        return root;
    }
};
// @lc code=end

