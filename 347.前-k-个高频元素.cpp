/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> feques;
        for(auto num : nums)
        {
            if(feques.find(num) == feques.end()) feques[num] = 1;
            else feques[num]++;
        }

        /* 通常情况下求前k大用小根堆，求前k小用大根堆 */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto fequ : feques) {
            minHeap.push(pair<int, int>(fequ.second, fequ.first));
            if (minHeap.size() > k) minHeap.pop();
        }

        //将前k个数值放入结果数组
        vector<int> k_frequent;
        while (k--) {
            k_frequent.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return k_frequent;
    }
};
// @lc code=end

