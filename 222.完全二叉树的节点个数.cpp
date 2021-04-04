/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include<vector>
#include<queue>
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
    int countNodes(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        queue<TreeNode*> Que;
        Que.push(root);
        while (!Que.empty()) {
            TreeNode* curQ = Que.front();
            if (curQ->left) Que.push(curQ->left);
            if (curQ->right) Que.push(curQ->right);
            Que.pop();
            result++;
        }
        return result;
    }
};
// @lc code=end

