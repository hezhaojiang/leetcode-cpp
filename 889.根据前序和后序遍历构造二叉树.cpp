/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* dfs(vector<int>& pre, int prel, int prer, vector<int>& post, int postl, int postr) {
        if (prel > prer || postl > postr) return nullptr;
        TreeNode* node = new TreeNode(pre[prel]);
        if (prel == prer) return node;
        int index =
            find(post.begin() + postl, post.begin() + postr + 1, pre[prel + 1]) - post.begin();
        node->left = dfs(pre, prel + 1, index - postl + prel + 1, post, postl, index);
        node->right = dfs(pre, index - postl + prel + 2, prer, post, index + 1, postr - 1);
        return node;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return dfs(pre, 0, n - 1, post, 0, n - 1);
    }
};
// @lc code=end

