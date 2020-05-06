/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include<vector> 
using namespace std;
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //把nums看成是顺序存储的链表，nums中每个元素的值是下一个链表节点的地址
        //那么如果nums有重复值，说明链表存在环，本问题就转化为了找链表中环的入口节点，因此可以用快慢指针解决
        
        //初始时，都指向链表第一个节点nums[0]
        int slow= 0, fast = 0;
        //慢指针走一步，快指针走两步
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // slow 与 fast 相遇，相遇节点必在环中，循环退出时
            if(slow == fast) break;
        }
        // 让 fast，slow 分别指向链表开始节点，相遇节点
        fast = 0;
        // fast 与 slow 相遇时，相遇点就是环的入口节点
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

