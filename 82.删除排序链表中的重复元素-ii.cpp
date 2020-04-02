/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode pre_head(0);
        ListNode* nodeCur = &pre_head;

        int valCur = 0;
        int valCnt = 0;
        ListNode* pre = nullptr;

        if(head)
        {
            valCur = head->val;
        }

        while(head)
        {
            if(head->val == valCur)
            {
                valCnt++;
            }
            else
            {
                if(1 == valCnt)
                {
                    nodeCur->next = pre;
                    nodeCur = pre;
                }
                valCnt = 1;
                valCur = head->val;
            }
            pre  = head;
            head = head->next;
        }
        if(1 == valCnt)
        {
            nodeCur->next = pre;
            nodeCur = pre;
        }

        nodeCur->next = nullptr;
        return pre_head.next;
    }
};
// @lc code=end

