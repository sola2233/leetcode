/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
/** 
 * 类似于 142 环形链表
 * 将输入数组看成一个链表，下标 i 是一个节点，下一个节点就是 nums[i]
 * 如果没有重复数字，快指针一定能等于 n，下标越界
 * 如果有重复数字，快慢指针一定会相等
 * 环的入口就是我们要找的重复数字，因为有多个节点指向它
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 快慢指针
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // 找环的入口
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

