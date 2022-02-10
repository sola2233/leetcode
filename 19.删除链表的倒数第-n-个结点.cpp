/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/** 
 * 链表问题，用双指针解决
 * 要找到倒数第 n 个节点，只需要 p1 先走 n 步即可，最后 p2 就指向倒数第 n 个节点
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
        // p1 先走 n 步，p2 指向虚拟头结点
        ListNode *p1 = head, *p2 = dummy;
        for (int i = 0; i < n; ++i)
        {
            p1 = p1->next;
        }

        // 循环停止时，p2 就指向倒数第 n+1 个节点
        while (p1)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        // 删除倒数第 n 个节点
        p2->next = p2->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
// @lc code=end

