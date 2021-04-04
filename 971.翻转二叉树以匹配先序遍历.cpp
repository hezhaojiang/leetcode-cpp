/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
 */
#include<vector>
#include<algorithm>
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
    int vsize; 
    vector<int> result;
    int dfs(TreeNode* root, vector<int>& voyage, int index) {
        if (!root || index == vsize) return index - 1;
        if (root->val != voyage[index]) return -1;
        if (root->left && root->left->val != voyage[index + 1]) {
            swap(root->left, root->right);
            result.push_back(root->val);
        }
        index = dfs(root->left, voyage, index + 1);
        if (index == -1) return -1;
        index = dfs(root->right, voyage, index + 1);
        if (index == -1) return -1;
        return index;
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vsize = voyage.size();
        if (-1 == dfs(root, voyage, 0)) return vector<int>{-1};
        return result;
    }
};
// @lc code=end

