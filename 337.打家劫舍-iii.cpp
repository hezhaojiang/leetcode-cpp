/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include<vector>
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
    int money = 0;
public:
    void dfs(TreeNode* root, int& hasRoot, int& unhasRoot) 
    {
        hasRoot = 0;
        unhasRoot = 0;
        if (!root) return;
        int hasRoot_l, unhasRoot_l;
        int hasRoot_r, unhasRoot_r;
        dfs(root->left, hasRoot_l, unhasRoot_l);
        dfs(root->right, hasRoot_r, unhasRoot_r);
        hasRoot = unhasRoot_l + unhasRoot_r + root->val;
        unhasRoot = max(hasRoot_l, unhasRoot_l) + max(hasRoot_r, unhasRoot_r);
        return;
    }
    int rob(TreeNode* root) {
        int hasRoot, unhasRoot;
        dfs(root, hasRoot, unhasRoot);
        return max(hasRoot, unhasRoot);
    }
};
// @lc code=end
int main()
{
    TreeNode a(4);
    TreeNode b(1);
    TreeNode c(2);
    TreeNode d(3);
    a.left = &b;
    b.left = &c;
    c.left = &d;
    Solution solve;
    return solve.rob(&a);
}
