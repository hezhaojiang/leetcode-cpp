/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* new_head = nullptr;
        while(head)
        {
            #ifdef hezhaojiang
            ListNode* temp = new_head;
            new_head = head;
            head = head->next;
            new_head->next = temp;
            #endif

            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        return new_head;
    }
};
// @lc code=end

