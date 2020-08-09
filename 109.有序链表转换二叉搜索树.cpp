/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<int> nums;
    TreeNode* halfDevide(int start, int end)
    {
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if(start != mid) root->left = halfDevide(start, mid - 1);
        if(mid != end) root->right = halfDevide(mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        if(nums.size() == 0) return nullptr;
        return halfDevide(0, nums.size() - 1);
    }
};
// @lc code=end

