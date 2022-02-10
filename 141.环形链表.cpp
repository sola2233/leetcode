/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/** 
 * 链表问题，通过快慢指针
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 快慢指针
        ListNode *fast = head, *slow = head;
        // 此处不需要判断 slow，因为 fast 更快
        while (fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;

            // 存在环路
            if (fast == slow)
                return true;
        }

        // 遇到空指针则没有环路
        return false;
    }
};
// @lc code=end

