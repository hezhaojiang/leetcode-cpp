/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums) q.push(num);
    }
    
    int add(int val) {
        q.push(val);
        while (q.size() > k) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

