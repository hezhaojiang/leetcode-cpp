/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDeep;
    vector<int> item;
public:
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        item.push_back(root->val);
        if(!root->left && !root->right && (minDeep == 0 || minDeep > item.size()))
            minDeep = item.size();
        preOrder(root->left);
        preOrder(root->right);
        item.pop_back();
        return;
    }
public:
    int minDepth(TreeNode* root) {
        preOrder(root);
        return minDeep;
    }
};
// @lc code=end

