/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include<vector>
#include<stack>
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
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        result.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        /* 递归 */
        // preOrder(root);
        /* 迭代 */
        stack<TreeNode*> node;
        TreeNode* cur = root;
        while(cur || !node.empty())
        {
            if(cur)
            {
                node.push(cur);
                result.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                cur = node.top();
                node.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

