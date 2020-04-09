/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool result;
public:
    void preOrder(TreeNode* p, TreeNode* q)
    {
        if(!result) return;
        if(!p && !q) return;
        if((p && !q) || (!p && q) || (p->val != q->val))
        {
            result = false;
            return;
        }
        preOrder(p->left, q->right);
        preOrder(p->right, q->left);
        return;
    }
    bool isSymmetric(TreeNode* root) {
        result = true;
        preOrder(root, root);
        return result;
    }
};
// @lc code=end

