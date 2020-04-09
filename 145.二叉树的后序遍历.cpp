/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> result;
public:
    void midOrder(TreeNode* root)
    {
        if(!root) return;
        midOrder(root->left);
        midOrder(root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        /* 递归 */
        midOrder(root);
        // TODO：非递归版本
        return result;
    }
};
// @lc code=end

