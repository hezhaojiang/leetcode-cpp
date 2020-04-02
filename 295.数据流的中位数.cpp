/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;
    std::priority_queue<int, std::vector<int>, std::less<int>> big_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small_heap.size() == big_heap.size())
        {
            if(0 == small_heap.size() || num > small_heap.top())
            {
                small_heap.push(num);
            }
            else
            {
                big_heap.push(num);
            }
        }
        else if(small_heap.size() > big_heap.size())
        {
            if(num > small_heap.top())
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
            else
            {
                big_heap.push(num);
            }
            
        }
        else if(small_heap.size() < big_heap.size())
        {
            if(num < big_heap.top())
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
            else
            {
                small_heap.push(num);
            }
        }
        return;
    }
    
    double findMedian() {
        if(small_heap.size() == big_heap.size())
        {
            if(0 == small_heap.size())
            {
                return 0;
            }
            else
            {
                return (small_heap.top() + big_heap.top())/2.0;
            }
        }
        else if(small_heap.size() > big_heap.size())
        {
            return small_heap.top();
        }
        else if(small_heap.size() < big_heap.size())
        {
            return big_heap.top();
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

