#include<list>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

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
    int maxResult(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0) return 0;
        vector<int> dp(N,INT_MIN);
        MaxQueue maxQ;
        dp[0] = nums[0];
        maxQ.push_back(nums[0]);
        for (int start = 0, i = 1; i < N; i++) {
            if (start + k < i) { maxQ.pop_front(); start++; }
            dp[i] = maxQ.max_value() + nums[i];
            maxQ.push_back(dp[i]);
        }
        return dp.back();
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> nums{10,-5,-2,4,0,3};
    solve.maxResult(nums, 3);
    return 0;
}