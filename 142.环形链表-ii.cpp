/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/** 
 * 链表问题，对于链表找环路有一个通用解法：快慢指针
 * [解释](https://labuladong.gitee.io/algo/2/21/59/)
 */
#include <stddef.h> /** NULL */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;

        // 判断是否存在环路
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            // 有环路时退出
            if (fast == slow)
                break;
        }
        // 不存在环路
        if (!fast || !fast->next)
            return nullptr;
        
        // 寻找环路开始节点
        fast = head;
        while (slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};
// @lc code=end

