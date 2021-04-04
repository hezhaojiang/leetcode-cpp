/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> M;
    TreeNode* dfs(vector<int>& inorder, int istart, int iend, 
                  vector<int>& postorder, int & pend) {
        if (istart > iend || pend < 0) return nullptr;
        int inpos = M[postorder[pend]];
        if (istart > inpos || inpos > iend) return nullptr;
        TreeNode* node = new TreeNode(postorder[pend--]);
        node->right = dfs(inorder, M[node->val] + 1, iend, postorder, pend);
        node->left = dfs(inorder, istart, M[node->val] - 1, postorder, pend);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int A = inorder.size();
        int B = postorder.size();
        int index = A - 1;
        if (A == 0 || A != B) return nullptr;
        for (int i = 0; i < inorder.size(); i++) M[inorder[i]] = i;
        return dfs(inorder, 0, inorder.size() - 1, postorder, index);
    }
};
// @lc code=end

