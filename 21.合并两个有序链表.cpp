/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(!l1)
        {
            return l2;
        }

        ListNode* start = l1;

        while(l2)
        {
            ListNode* next2 = l2->next;
            while(l1)
            {
                if(l1->val > l2->val)
                {
                    l2->next = l1;
                    l1 = l2;
                    start = l2;
                    break;
                }
                if(nullptr == l1->next || l1->next->val > l2->val)
                {
                    l2->next = l1->next;
                    l1->next = l2;
                    break;
                }
                l1 = l1->next;
            }
            l2 = next2;
        }
        return start;
    }
};
// @lc code=end

