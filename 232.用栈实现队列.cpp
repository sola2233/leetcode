/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
using namespace std;
class MyQueue {
public:
    MyQueue() {
        size_ = 0;
    }
    
    void push(int x) {
        stk_in.push(x);
        size_++;
    }
    
    int pop() {
        // 只有当 stk_out 为空的时候，再从 stk_in 里导入数据（导入 stk_in 全部数据）
        if (stk_out.empty())
            while (!stk_in.empty())
            {
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        int res = stk_out.top();
        stk_out.pop();
        size_--;

        return res;
    }
    
    int peek() {
        // 复用 pop 函数
        int res = pop();
        // 再放回队列中
        stk_out.push(res);
        size_++;

        return res;     
    }
    
    bool empty() {
        if (size_ == 0)
            return true;
        return false;
    }
private:
    int size_;
    stack<int> stk_in;
    stack<int> stk_out;
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

