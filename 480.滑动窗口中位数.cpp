/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<iterator>
using namespace std;
// @lc code=start
class MedianFinder {
private:
    // 升序队列 小根堆 保存大一些的数字
    priority_queue<int, vector<int>, greater<int>> large;
    // 降序队列 大根堆 保存小一些的数字
    priority_queue<int, vector<int>, less<int>> small;
    // 哈希表，记录「延迟删除」的元素，key 为元素，value 为需要删除的次数
    unordered_map<int, int> delayed;
    // small 和 large 当前包含的元素个数，需要扣除被「延迟删除」的元素
    int smallSize, largeSize;
public:
    /** initialize your data structure here. */
    MedianFinder() : smallSize(0), largeSize(0) {}
    
    template<typename T>
    void prune(T& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                --delayed[num];
                if (!delayed[num]) delayed.erase(num);
                heap.pop();
            } else break;
        }
    }

    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        prune(small);
        if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            prune(large);
            ++smallSize;
        } else ++largeSize;
    }

    void delNum(int num) {
        ++delayed[num];
        if (num < large.top()) {
            --smallSize;
            if (num == small.top()) prune(small);
            if (smallSize + 1 < largeSize) {
                small.push(large.top());
                large.pop();
                prune(large);
                ++smallSize;
                --largeSize;
            }
        } else {
            --largeSize;
            if (num == large.top()) prune(large);
        }
    }
    
    double findMedian() {
        if (large.empty() && small.empty()) return 0;
        if (smallSize == largeSize) return (0LL + small.top() + large.top()) / 2.0;
        else if (smallSize > largeSize) return small.top();
        else return large.top();
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int N = nums.size();
        int count = 0;
        int left = 0, right = 0;
        MedianFinder uf;
        while (right < N) {
            uf.addNum(nums[right++]);
            if (++count > k) uf.delNum(nums[left++]);
            if (right - left == k) res.push_back(uf.findMedian());
        }

#ifdef DST
        vector<double> res;
        multiset<double> st;
        for (int i = 0; i < nums.size(); ++i) {
            if (st.size() >= k) st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            if (i >= k - 1) {
                auto mid = st.begin();
                std::advance(mid, k / 2);
                res.push_back((*mid + *prev(mid, (1 - k % 2))) / 2);
            }
        }
#endif
        return res;
    }
};
// @lc code=end

int main()
{
    Solution slove;
    vector<int> nums{7,9,3,8,0,2,4,8,3,9};
    slove.medianSlidingWindow(nums, 1);
    return 0;
}

