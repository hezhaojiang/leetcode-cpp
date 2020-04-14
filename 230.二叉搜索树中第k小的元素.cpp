/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    vector<TreeNode*> item;
public:
    int kthSmallest(TreeNode* root, int k) {
        while(root)
        {
            item.push_back(root);
            root = root->left;
        }
        while(--k)
        {
            TreeNode* ret = item.back();
            int result = ret->val;
            item.pop_back();
            ret = ret->right;
            while(ret)
            {
                item.push_back(ret);
                ret = ret->left;
            }
        }
        return item.back()->val;
    }
};
// @lc code=end

