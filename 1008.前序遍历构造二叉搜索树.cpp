/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */
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
private:
    TreeNode* dfs(vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* node = new TreeNode(preorder[l]);
        int split = l + 1;
        while (split <= r && preorder[split] < preorder[l]) split++;
        node->left = dfs(preorder, l + 1, split - 1);
        node->right = dfs(preorder, split, r);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return dfs(preorder, 0, n - 1);
    }
};
// @lc code=end

