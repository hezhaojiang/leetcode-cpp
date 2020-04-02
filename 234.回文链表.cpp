/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std:stack <int> NodeStack;
        ListNode* cur = head;
        while(cur)
        {
            NodeStack.push(cur->val);
            cur = cur->next;
        }
        while(head)
        {
            if(NodeStack.top() != head->val)
            {
                return false;
            }
            NodeStack.pop();
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

