/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/** 
 * 链表问题，用双指针解决
 * 要找到倒数第 n 个节点，只需要 fast 先走 n 步即可，最后 slow 就指向倒数第 n 个节点
 * 此处要删除，这里又是单向链表，所以要找到倒数第 n+1 个节点，然后删除他的后继
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 虚拟头结点，防止链表删光的情况
        ListNode *dummy = new ListNode(0, head);
        // fast 首先走 n+1 步，因为只有这样同时移动的时候 slow 才能指向删除节点的上一个节点
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i < n + 1; ++i)
            fast = fast->next;

        // 循环停止时，slow 就指向倒数第 n+1 个节点
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // 删除倒数第 n 个节点
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;

        return dummy->next;
    }
};
// @lc code=end

