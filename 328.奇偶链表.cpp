/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        int nodetag = 0;
        ListNode* start_Odd = head;
        head = head->next;
        ListNode* start_Even = head;
        head = head->next;

        ListNode* end_Odd = start_Odd;
        ListNode* end_Even = start_Even;

        while(nodetag++, head)
        {
            ListNode* next = head->next;

            if(0 != nodetag % 2)
            {
                end_Odd->next = head;
                end_Odd = end_Odd->next;
            }
            else
            {
                end_Even->next = head;
                end_Even = end_Even->next;
            }
            head = next;
        }
        end_Odd->next = start_Even;
        end_Even->next = nullptr;
        return start_Odd;
    }
};
// @lc code=end

