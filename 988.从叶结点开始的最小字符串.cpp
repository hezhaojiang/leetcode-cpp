/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
 */
#include<vector>
#include<string>
#include<algorithm>
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
    string s;
    string mins;
    void dfs(TreeNode* root) {
        if (!root) return;
        s += (char)('a' + root->val);
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            if (mins.empty()) mins = s;
            else mins = min(mins, s);
            reverse(s.begin(), s.end());
        }
        else {
            if (root->left) smallestFromLeaf(root->left);
            if (root->right) smallestFromLeaf(root->right);
        }
        s.resize(s.size() - 1);
        return;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return mins;
    }
};
// @lc code=end

