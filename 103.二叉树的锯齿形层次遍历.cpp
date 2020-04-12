/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    queue<TreeNode*> Que;
    int line;
    vector<int> item;
    vector<vector<int>> result;
public:
    void SeqTraverse()
    {
        if(Que.empty()) return;
        TreeNode* curQ;
        
        while(!Que.empty())
        {
            item.clear();
            int size = Que.size();
            for(int i = 0; i < size; i++)
            {
                curQ = Que.front();
                if(curQ->left) Que.push(curQ->left);
                if(curQ->right) Que.push(curQ->right);
                item.push_back(curQ->val);
                Que.pop();
            }
            if(line++ % 2 == 0) reverse(item.begin(), item.end());
            result.push_back(item);
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root)
        {
            line = 1;
            Que.push(root);
            SeqTraverse();
        }
        return result;
    }
};
// @lc code=end

