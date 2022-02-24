/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
/** 
 * 单调队列，这里维护一个单调递减队列，用 deque 实现
 */
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    class MyQueue
    {
    public:
        MyQueue()
        {

        }

        void push(int x)
        {
            // 弹出队列尾部比 x 小的元素，维持一个单调递减队列
            while (!q_.empty() && q_.back() < x)
                q_.pop_back();
            q_.push_back(x);
        }

        void pop(int x)
        {
            // 只有 x 是队列头部元素时，才出队列
            if (!q_.empty() && q_.front() == x)
                q_.pop_front();
        }

        int front()
        {
            // 队列头部元素就是此时队列中最大元素
            return q_.front();
        }
    private:
        // 使用deque来实现单调队列
        deque<int> q_;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        int left = 0, right = 0;
        // 滑动窗口
        while (right < nums.size())
        {
            // 扩大窗口
            que.push(nums[right]);
            right++;
            // 缩小窗口条件，维护一个 [left, right) 的窗口，左闭右开
            if (right - left == k)
            {
                // 更新答案
                res.push_back(que.front());
                // 缩小窗口
                que.pop(nums[left]);
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

