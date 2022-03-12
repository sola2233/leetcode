/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        // 虚拟头节点
        ListNode* dummy = new ListNode(0, head);
        ListNode* p1 = head; // p1 是已排序区域的最后一个节点
        while (p1->next != nullptr)
        {
            // 当前待插入节点
            ListNode* cur = p1->next;
            // 从头节点开始在已排序区域比较，找到第一个大于等于 p1 的节点的前驱节点
            ListNode* prev = dummy; // prev 是插入节点 cur 位置的前一个节点
            while (prev->next->val < cur->val && prev->next != cur)
                prev = prev->next;
            if (prev == p1) // 相等说明 cur 的位置不需要改变
            {
                // p1 移动到下一个位置
                p1 = p1->next;
                continue;
            }
            // 从原位置删除
            p1->next = p1->next->next;
            // 插入 cur
            cur->next = prev->next;
            prev->next = cur;
        }
        return dummy->next;
    }
};
// @lc code=end

