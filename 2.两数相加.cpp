/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)  {
        ListNode  pre_head(0);
        ListNode* currNode = &pre_head;

        int flag = 0;
        int val = 0;

        while(l1 && l2) {
            val = l1->val + l2->val + flag;
            ListNode* node = new ListNode(val % 10);
            currNode->next = node;
            flag = val / 10;
            l1 = l1->next;
            l2 = l2->next;
            currNode = currNode->next;
        }
        while(l1) {
            val = l1->val + flag;
            ListNode* node = new ListNode(val % 10);
            currNode->next = node;
            flag = val / 10;
            l1 = l1->next;
            currNode = currNode->next;
        }
        while(l2) {
            val = l2->val + flag;
            ListNode* node = new ListNode(val % 10);
            currNode->next = node;
            flag = val / 10;
            l2 = l2->next;
            currNode = currNode->next;
        }
        if(flag) {
            ListNode* node = new ListNode(1);
            currNode->next = node;
        }
        return pre_head.next;
    }
};
// @lc code=end

