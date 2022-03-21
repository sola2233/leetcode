/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
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
    ListNode* removeElements(ListNode* head, int val) {
        // 虚拟头节点
        ListNode* dummy = new ListNode(0, head);
        // 遍历链表
        ListNode* cur = dummy;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                // 删除节点
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
                // 只有 next 的值不为 val 才能后移
                cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

