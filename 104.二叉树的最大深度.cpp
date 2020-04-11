/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDeep;
    vector<int> item;
public:
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        item.push_back(root->val);
        if(!root->left && !root->right && maxDeep < item.size())
            maxDeep = item.size();
        preOrder(root->left);
        preOrder(root->right);
        item.pop_back();
        return;
    }
    int maxDepth(TreeNode* root) {
        preOrder(root);
        return maxDeep;
    }
};
// @lc code=end

