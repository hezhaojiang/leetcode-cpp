/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include<vector>
#include<queue>
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
    queue<TreeNode*> Que1;
    queue<TreeNode*> Que2;
    vector<int> result;
public:
    void SeqTraverse()
    {
        if(Que1.empty()) return;
        TreeNode* curQ;
        while(!Que1.empty())
        {
            curQ = Que1.front();
            if(curQ->left) Que2.push(curQ->left);
            if(curQ->right) Que2.push(curQ->right);
            Que1.pop();
        }
        result.push_back(curQ->val);
        while(!Que2.empty())
        {
            Que1.push(Que2.front());
            Que2.pop();
        }
        SeqTraverse();
        return;
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root)
        {
            Que1.push(root);
            SeqTraverse();
        }
        return result;
    }
};
// @lc code=end

