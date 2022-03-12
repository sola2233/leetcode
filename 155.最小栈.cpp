/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
/** 
 * 设置一个辅助栈，存放最小值
 */
#include <stack>
#include <cstdint>
using namespace std;
class MinStack {
public:
    stack<int> stk;
    stack<int> min_stk;

    MinStack() {
        min_stk.push(INT32_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        min_stk.push(min(val, min_stk.top()));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

