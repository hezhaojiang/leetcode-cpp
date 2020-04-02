/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp_node(0);
        temp_node.next = head;
        ListNode* pre_node = &temp_node;
        ListNode* after_node = &temp_node;

        while(n--)
        {
            pre_node = pre_node->next;
        }
        while(pre_node->next)
        {
            after_node = after_node->next;
            pre_node = pre_node->next;
        }
        after_node->next = after_node->next->next;
        return temp_node.next;
    }
};
// @lc code=end

