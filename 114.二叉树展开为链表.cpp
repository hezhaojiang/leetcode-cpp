/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
private:
    TreeNode list;
    TreeNode* pos;
public:
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        pos->left = nullptr;
        pos->right = root;
        pos = pos->right;

        preOrder(left);
        preOrder(right);
        return;
    }
    void flatten(TreeNode* root)
    {
        pos = &list;
        preOrder(root);
        return;
    }
};
// @lc code=end

