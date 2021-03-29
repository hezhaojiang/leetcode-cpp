/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <queue>
#include <vector>
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> piece;
            for (int i = 0; i < n; i++) {
                TreeNode *node = Q.front();
                piece.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
            res.push_back(piece);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
