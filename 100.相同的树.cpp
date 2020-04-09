/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
        preOrder(p->left, q->left);
        preOrder(p->right, q->right);
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        result = true;
        preOrder(p, q);
        return result;
    }
};
// @lc code=end

