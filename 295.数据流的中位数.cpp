/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// @lc code=start
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> small_heap;  // 升序队列 小根堆 保存大一些的数字
    priority_queue<int, vector<int>, less<int>> big_heap;       // 降序队列 大根堆 保存小一些的数字
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        small_heap.push(num);
        big_heap.push(small_heap.top());
        small_heap.pop();
        if (small_heap.size() + 1 < big_heap.size()) {
            small_heap.push(big_heap.top());
            big_heap.pop();
        }
    }
    
    double findMedian() {
        if (big_heap.empty()) return 0;
        if (small_heap.size() == big_heap.size()) {
            return (small_heap.top() + big_heap.top()) / 2.0;
        } else return big_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.findMedian();
    return 0;
}
