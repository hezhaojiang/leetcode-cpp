/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */
#include<vector>
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
private:
    int Target;
    vector<int64_t> item;
    
    int dfs(TreeNode* root, int last) {
        if (!root) return 0;
        int targetCount = 0;
        int count = item.size();
        for (int i = count - last; i < count; i++) { 
            int64_t sum = root->val + item[i];
            item.push_back(sum);
            if (sum == Target) targetCount++;
        }
        item.push_back(root->val);
        if (root->val == Target) targetCount++;
        targetCount += dfs(root->left, last + 1) + dfs(root->right, last + 1);
        for (int i = 0; i <= last; i++) item.pop_back();
        return targetCount;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        Target = sum;
        return dfs(root, 0);
    }
};
// @lc code=end

