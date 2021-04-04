/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include <iostream>
using namespace std;

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
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode preNode(0);
        ListNode* pre = &preNode;
        preNode.next = head;

        int count = n - m; // 调节节点顺序的次数
        while (--m) pre = pre->next; // 找到 m 节点之前的节点
        ListNode* cur = pre->next;   // 找到 m 节点

        // 将 cur->next 指向的节点放到 pre 之后
        while (count--) {
            ListNode* node = cur->next;
            // 删除 node
            cur->next = node->next;
            // 将 node 插入到 pre 后
            node->next = pre->next;
            pre->next = node;
        }
        return preNode.next;
    }
};
// @lc code=end

