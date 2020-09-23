/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */
#include<iostream>
#include<string>
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
    string tree2str(TreeNode* t) {
        string s;
        if (!t) return s;
        s += to_string(t->val);
        if (t->left || t->right) s += '(' + tree2str(t->left) + ')';
        if (t->right) s += '(' + tree2str(t->right) + ')';
        return s;
    }
};
// @lc code=end

