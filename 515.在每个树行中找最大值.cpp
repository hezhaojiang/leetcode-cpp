/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */
#include<vector>
#include<queue>
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        int maxValue;
        if (!root) return result;
        queue<TreeNode*> Que;
        Que.push(root);
        while (!Que.empty()) {
            int count = Que.size();
            for (int i = 0; i < count; i++) {
                TreeNode* curQ = Que.front();
                if (i == 0) maxValue = curQ->val;
                else maxValue = max(maxValue, curQ->val);
                if (curQ->left) Que.push(curQ->left);
                if (curQ->right) Que.push(curQ->right);
                Que.pop();
            }
            result.push_back(maxValue);
        }
        return result;
    }
};
// @lc code=end

