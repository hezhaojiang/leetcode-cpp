/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
struct ListNode {
  int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode preNode(0);
        preNode.next = head;
        ListNode* slowNode = &preNode;
        ListNode* fastNode = &preNode;

        while (n--) fastNode = fastNode->next; // 快指针先移动 n 个结点
        while (fastNode->next) { // 慢指针和快指针同时移动 找到第 n - 1 个结点
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        slowNode->next = slowNode->next->next;
        return preNode.next;
    }
};
// @lc code=end

