/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include<vector> 
#include<algorithm>
#include<stack>
using namespace std;
// @lc code=start
class MinStack {
private:
    int minValue;
    std::stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(minStack.empty()) minValue = x;
        if(x <= minValue) 
        {
            minStack.push(minValue);
            minValue = x;
        }
        minStack.push(x);
        return;
    }
    
    void pop() {
        int topValue = minStack.top();
        minStack.pop();
        if(minValue == topValue)
        {
            minValue = minStack.top();
            minStack.pop();
        }
        return;
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return minValue;
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

