/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeNode> Tree;
    TreeNode* halfDevide(vector<int>& nums, int start, int end)
    {
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(start != mid) root->left = halfDevide(nums, start, mid - 1);
        if(mid != end) root->right = halfDevide(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return halfDevide(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

