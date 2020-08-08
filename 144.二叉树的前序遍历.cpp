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
//#define REVERSE1
//#define REVERSE2
//#define ITERATION
#define MORRIS
#ifdef REVERSE1
    void preOrder(TreeNode* root)
    {
        if(!root) return;
        result.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
#endif
    vector<int> preorderTraversal(TreeNode* root) 
    {
#ifdef REVERSE1
        /* 递归 1 */
        preOrder(root);
        return result;
#endif
#ifdef REVERSE2
        /* 递归 2 */
        vector<int> result;
        if(!root) return result;

        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);

        result.push_back(root->val);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());

        return result;
#endif
#ifdef ITERATION
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
#endif
#ifdef MORRIS
        if(!root) return result;
        TreeNode* cur = root;
        while(cur)
        {
            if(cur->left)
            {
                /* 如果存在左子树，则需要设置索引 */
                TreeNode* index = cur->left;
                while(index->right && index->right != cur)
                {
                    index = index->right;
                }
                
                if(!index->right)
                {
                    /* 首次寻找到索引，设置索引，继续遍历左子树 */
                    result.push_back(cur->val);
                    index->right = cur;
                    cur = cur->left;
                }
                else
                {
                    /* 非首次寻找到索引，说明左子树遍历完成，根据索引去遍历右子树 */
                    cur = cur->right;
                    /* 恢复索引 */
                    index->right = nullptr;
                }
            }
            else
            {
                /* 没有左子树 遍历右子树 */
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
#endif
    }
};
// @lc code=end

