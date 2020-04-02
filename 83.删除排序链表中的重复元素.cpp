/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
        ListNode* nodeCur = head;
        while(nodeCur && nodeCur->next)
        {
            if(nodeCur->val == nodeCur->next->val)
            {
                nodeCur->next = nodeCur->next->next;
            }
            else
            {
                nodeCur = nodeCur->next;
            }
        }
        return head;
    }
};
// @lc code=end

