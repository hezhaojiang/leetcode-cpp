/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include<iostream>
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
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> node;
        TreeNode* cur = root;
        int result = INT_MAX;
        bool isFirst = true;
        int preVal = 0;
        while(cur || !node.empty()) {
            if(cur) {
                node.push(cur);
                cur = cur->left;
            }
            else {
                cur = node.top();
                if (!isFirst) result = min(result, cur->val - preVal);
                if (isFirst) isFirst = !isFirst;
                preVal = cur->val;
                node.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end

