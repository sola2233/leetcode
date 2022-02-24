/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;
class MyStack {
public:
    MyStack() {
        size_ = 0;
    }
    
    void push(int x) {
        // 哪个队列有数据往哪个放
        if (!q1_.empty())
            q1_.push(x);
        else if (!q2_.empty())
            q2_.push(x);
        else // 都为空就直接放到 q1 里
            q1_.push(x);
        size_++;
    }
    
    int pop() {
        int res;
        if (!q1_.empty())
        {
            for (int i = 0; i < size_ - 1; ++i)
            {
                int tmp = q1_.front();
                q2_.push(tmp);
                q1_.pop();
            }
            // 弹出刚刚放进的最后一个元素
            res = q1_.front();
            q1_.pop();
        }
        else
        {
            for (int i = 0; i < size_ - 1; ++i)
            {
                int tmp = q2_.front();
                q1_.push(tmp);
                q2_.pop();
            }
            // 弹出刚刚放进的最后一个元素
            res = q2_.front();
            q2_.pop();
        }
        size_--;

        return res;
    }
    
    int top() {
        // 复用 pop 函数
        int res = pop();
        // 再放回去
        push(res);

        return res;
    }
    
    bool empty() {
        return size_ == 0 ? true : false;
    }
private:
    queue<int> q1_;
    queue<int> q2_;
    int size_;
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

