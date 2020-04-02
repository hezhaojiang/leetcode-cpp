/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* pre_less = nullptr;
        ListNode* end_less = nullptr;
        ListNode* pre_more = nullptr;
        ListNode* end_more = nullptr;

        while(head)
        {
            ListNode* next = head->next;
            if(head->val < x)
            {
                if(!pre_less)
                {
                    pre_less = head;
                    end_less = head;
                    end_less->next = nullptr;
                }
                else
                {
                    end_less->next = head;
                    end_less = head;
                    end_less->next = nullptr;
                }
            }
            else
            {
                if(!pre_more)
                {
                    pre_more = head;
                    end_more = head;
                    end_more->next = nullptr;
                }
                else
                {
                    end_more->next = head;
                    end_more = head;
                    end_more->next = nullptr;
                }
            }
            head = next;
        }
        if(!pre_less && !pre_more)
        {
            return nullptr;
        }
        else if(!pre_less && pre_more)
        {
            return pre_more;
        }
        else if(pre_less && !pre_more)
        {
            return pre_less;
        }
        else
        {
            end_less->next = pre_more;
            return pre_less;
        }
        
    }
};
// @lc code=end

