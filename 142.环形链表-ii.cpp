/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = nullptr;

        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(nullptr == fast)
            {
                break;
            }

            fast = fast->next;

            if(slow == fast)
            {
                meet = slow;
                fast = head;
                break;
            }
        }

        while(meet)
        {
            if(slow == fast)
            {
                return slow;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return nullptr;
    }
};
// @lc code=end

