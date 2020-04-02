/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    std::stack<int> mindata;
    std::stack<int> data;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(mindata.empty() || mindata.top() > x)
        {
            mindata.push(x);
        }
        else
        {
            mindata.push(mindata.top());
        }
        data.push(x);
        return;
    }
    
    void pop() {
        data.pop();
        mindata.pop();
        return;
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mindata.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

