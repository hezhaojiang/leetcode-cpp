/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include<vector>
#include<stack>
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
    vector<TreeNode*> item;
    vector<TreeNode*> result1;
    vector<TreeNode*> result2;
public:
    void preOrder(TreeNode* root, TreeNode* target1, TreeNode* target2)
    {
        if(!root) return;
        if(root == target1)
        {
            item.push_back(root);
            result1 = item;
            item.pop_back();
        }
        else if(root == target2)
        {
            item.push_back(root);
            result2 = item;
            item.pop_back();
        }
            
        item.push_back(root);
        preOrder(root->left, target1, target2);
        preOrder(root->right, target1, target2);
        item.pop_back();
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preOrder(root, p, q);
        //return root;
        int i = 0;
        for(i = 0; i < min(result1.size(), result2.size()); i++)
        {
            if(result1[i] != result2[i]) break;
        }
        return result1[i - 1];
    }
};
// @lc code=end

