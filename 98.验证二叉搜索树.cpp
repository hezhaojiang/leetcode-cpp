/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    int result = true;
public:
    void dfs(TreeNode* root, int& submin, int& submax) 
    {
        if(!root || !result) return;

        int lmin = 0x80000000, lmax = 0x7FFFFFFF;
        int rmin = 0x80000000, rmax = 0x7FFFFFFF;

        dfs(root->left, lmin, lmax);
        dfs(root->right, rmin, rmax);
        
        if(root->left && !root->right)
        {
            if(lmax >= root->val) result = false;
            else
            {
                submin = lmin;
                submax = root->val;
            }
            return;
        }
        
        if(!root->left && root->right)
        {
            if(rmin <= root->val) result = false;
            else
            {
                submin = root->val;
                submax = rmax;
            }
            return;
        }

        if(root->left && root->right)
        {
            if(lmax >= root->val) result = false;
            else if(rmin<= root->val) result = false;
            else
            {
                submin = lmin;
                submax = rmax;
            }
             return;
        }

        if(!root->left && !root->right)
        {
            submin = root->val;
            submax = root->val;
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        int smin, smax;
        dfs(root, smin, smax);
        return result;
    }
};
// @lc code=end

