/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include<vector>
#include<algorithm>
#include<cmath>
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
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) return { nullptr };
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> l = generateTrees(start, i - 1);
            vector<TreeNode*> r = generateTrees(i + 1, end);
            for (auto left : l) for (auto right : r) {
                TreeNode* node = new TreeNode(i);
                node->left = left;
                node->right = right;
                allTrees.push_back(node);
            }
        }
        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }
};
// @lc code=end

