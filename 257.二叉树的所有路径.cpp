/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include<vector>
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
private:
    string item;
    vector<string> result;
public:
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        string temp = item;
        if(item.length() == 0) item = to_string(root->val);
        else item = item + "->" + to_string(root->val);
        if(!root->left && !root->right) result.push_back(item);
        preOrder(root->left);
        preOrder(root->right);
        item = temp;
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        preOrder(root);
        return result;
    }
};
// @lc code=end

