/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 */
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int minValue = 0;
    int min2Value = -1;
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->val > minValue)
            if (min2Value == -1) min2Value = root->val;
            else min2Value = min(min2Value, root->val);
        else dfs(root->left), dfs(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode *root) {
        minValue = root->val;
        dfs(root);
        return min2Value;
    }
};
// @lc code=end
