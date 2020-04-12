/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
            result.push_back(item);
            //result.insert(result.begin(), item);
        }
        return;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if(root)
        {
            Que.push(root);
            SeqTraverse();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

