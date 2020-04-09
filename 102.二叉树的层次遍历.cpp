/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
    vector<int> item;
    vector<vector<int>> result;
public:
    void SeqTraverse()
    {
        if(Que1.empty()) return;
        TreeNode* curQ;
        item.clear();
        while(!Que1.empty())
        {
            curQ = Que1.front();
            if(curQ->left) Que2.push(curQ->left);
            if(curQ->right) Que2.push(curQ->right);
            item.push_back(curQ->val);
            Que1.pop();
        }
        result.push_back(item);
        while(!Que2.empty())
        {
            Que1.push(Que2.front());
            Que2.pop();
        }
        SeqTraverse();
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root)
        {
            Que1.push(root);
            SeqTraverse();
        }
        return result;
    }
};
// @lc code=end

