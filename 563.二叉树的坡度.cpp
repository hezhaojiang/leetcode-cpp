/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 */
#include<iostream>
#include<algorithm>
#include<cmath>
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
    int sum_dfs(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum_dfs(root->left) + sum_dfs(root->right);
    }
public:
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        return abs(sum_dfs(root->right) - sum_dfs(root->left)) + findTilt(root->left) + findTilt(root->right);
    }
};
// @lc code=end

