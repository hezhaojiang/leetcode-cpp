/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include<queue> 
using namespace std;
// @lc code=start
class MyStack {
private:
    std::queue<int> data_queue;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int length = data_queue.size();
        data_queue.push(x);
        while(length--)
        {
            data_queue.push(data_queue.front());
            data_queue.pop();
        }
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = data_queue.front();
        data_queue.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return data_queue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

