/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void midOrder(TreeNode* root)
    {
        if(!root) return;
        midOrder(root->left);
        result.push_back(root->val);
        midOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        /* 递归 */
        //midOrder(root);
        /* 迭代 */
        stack<TreeNode*> node;
        TreeNode* cur = root;
        while(cur || !node.empty())
        {
            if(cur)
            {
                node.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = node.top();
                result.push_back(cur->val);
                node.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

