/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> M;
    TreeNode* dfs(vector<int>& inorder, int istart, int iend, 
                  vector<int>& preorder, int & pstart) {
        if (istart > iend || pstart == inorder.size()) return nullptr;
        int inpos = M[preorder[pstart]];
        if (istart > inpos || inpos > iend) return nullptr;
        TreeNode* node = new TreeNode(preorder[pstart++]);
        node->left = dfs(inorder, istart, M[node->val] - 1, preorder, pstart);
        node->right = dfs(inorder, M[node->val] + 1, iend, preorder, pstart);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int A = inorder.size();
        int B = preorder.size();
        int index = 0;
        if (A == 0 || A != B) return nullptr;
        for (int i = 0; i < inorder.size(); i++) M[inorder[i]] = i;
        return dfs(inorder, 0, inorder.size() - 1, preorder, index);
    }
};
// @lc code=end

