/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        while (node) {
            ListNode* next = node->next;
            nodes.push_back(node);
            node = next;
        }

        int N = nodes.size();
        for (int i = 0; i < N - 2 - i; i++) {
            // 遍历每个 i 的节点 将 N - 2 - i 的后一个节点放到 i 节点之后
            // 结束条件：i >= N - 2 - i
            nodes[N - 2 - i]->next = nodes[N - 1 - i]->next;
            nodes[N - 1 - i]->next = nodes[i + 1];
            nodes[i]->next = nodes[N - 1 - i];
        }
        return;
    }
};
// @lc code=end
