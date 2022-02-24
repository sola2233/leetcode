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
        ListNode* slow = dummy;
        while (slow->next != nullptr)
        {
            if (slow->next->val == val)
            {
                // 删除节点
                ListNode* tmp = slow->next;
                slow->next = slow->next->next;
                delete tmp;
            }
            else
                // 只有 next 的值不为 val 才能后移
                slow = slow->next;
        }
        return dummy->next;
    }
};
// @lc code=end

