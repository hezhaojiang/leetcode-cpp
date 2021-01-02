/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include<vector>
#include<list>
#include<queue>
using namespace std;
// @lc code=start
class MaxQueue {
private:
    queue<int> que;
    list<int> maxQueue;
public:
    MaxQueue() {}
    int max_value() {
        if (maxQueue.empty()) return -1;
        return maxQueue.front();
    }
    void push_back(int value) {
        que.push(value);
        while (!maxQueue.empty() && value > maxQueue.back()) maxQueue.pop_back();
        maxQueue.push_back(value);
    }
    int pop_front() {
        if (que.empty()) return -1;
        int front = que.front();
        que.pop();
        if (!maxQueue.empty() && maxQueue.front() == front) maxQueue.pop_front();
        return front;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MaxQueue mq;
        vector<int> res;
        int N = nums.size();
        for (int i = 0, left = 0, right = 0; i <= N - k; i++) {
            while (right < i + k) mq.push_back(nums[right++]);
            while (left < i) { mq.pop_front(); left++; }
            res.push_back(mq.max_value());
        }
        return res;
    }
};
// @lc code=end

