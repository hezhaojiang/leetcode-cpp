/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        int change_len = n - m + 1;
        ListNode* pre_head = nullptr;
        ListNode* result = head;

        while(head && --m)
        {
            pre_head = head;
            head = head->next;
        }

        ListNode* modify_list_tail = head;
        ListNode* new_head = nullptr;

        while(head && change_len)
        {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }

        modify_list_tail->next = head;

        if(pre_head)
        {
            pre_head->next = new_head;
        }
        else
        {
            result = new_head;
        }
        
        return result;
    }
};
// @lc code=end

