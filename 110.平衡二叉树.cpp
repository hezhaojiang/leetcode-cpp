/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    bool result;
public:
    int isBalancedReverse(TreeNode* root)
    {
        if(!root) return 0;
        int leftDeep = isBalancedReverse(root->left);
        int rightDeep = isBalancedReverse(root->right);
        if(abs(leftDeep - rightDeep) > 1) result = false;
        return max(leftDeep, rightDeep) + 1;
    }
    bool isBalanced(TreeNode* root) {
        result = true;
        isBalancedReverse(root);
        return result;
    }
};
// @lc code=end

