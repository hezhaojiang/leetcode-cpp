/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    std::stack<int> data_stack;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        std::stack<int> temp_stack;
        while(!data_stack.empty())
        {
            temp_stack.push(data_stack.top());
            data_stack.pop();
        }
        data_stack.push(x);
        while(!temp_stack.empty())
        {
            data_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = data_stack.top();
        data_stack.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        return data_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

