/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA, *nodeB = headB;
        while (nodeA != nodeB) {
            if (nodeA) nodeA = nodeA->next;
            else nodeA = headA;
            if (nodeB) nodeB = nodeB->next;
            else nodeB = headB;
        }
        return nodeA;

        // 以上为以下代码的简化版本
        // ListNode *fastNodeA = headA, *slowNodeA = headA;
        // ListNode *fastNodeB = headB, *slowNodeB = headB;
        // while (fastNodeA || fastNodeB) {
        //     if (fastNodeA) fastNodeA = fastNodeA->next;
        //     else slowNodeB = slowNodeB->next;
        //     if (fastNodeB) fastNodeB = fastNodeB->next;
        //     else slowNodeA = slowNodeA->next;
        // }
        // while (slowNodeA != slowNodeB) {
        //     slowNodeA = slowNodeA->next;
        //     slowNodeB = slowNodeB->next;
        // }
        // return slowNodeA;
    }
};
// @lc code=end

