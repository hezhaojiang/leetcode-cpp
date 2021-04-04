/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include<iostream>
#include<stack>
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
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(!root)
            return false;
        if(root->val == sum && !root->left && !root->right)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
// @lc code=end
int main()
{
    TreeNode a(1);
    TreeNode b(2);
    a.left = &b;
    Solution solve;
    cout << solve.hasPathSum(&a, 1) << endl;
}

