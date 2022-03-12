/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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
 * 方法1.交换到链表最后删除，效率不高 o(n)
 * 方法2.交换到后一个节点，删除后一个节点 o(1)
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *cur = node, *nxt = cur->next;
        cur->val = cur->next->val;
        cur->next = cur->next->next;
        delete nxt;
    }
};
// @lc code=end

