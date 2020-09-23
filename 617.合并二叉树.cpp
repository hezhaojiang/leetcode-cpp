/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* dfs(TreeNode* a, TreeNode* b){
        if (!a && !b) return nullptr;
        if (a && b) {
            a->val += b->val;
            a->left = dfs(a->left, b->left);
            a->right = dfs(a->right, b->right);
        }
        else if (b) {
           return b;
        }
        return a;
    }
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }
};
// @lc code=end

