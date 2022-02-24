/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/** 
 * 递归 + 迭代反转一个区间
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
    ListNode* swapPairs(ListNode* head) {
        // 负例
        if (head == nullptr)
            return head;
        // base case，不足两个
        ListNode *a = head, *b = head;
        for (int i = 0; i < 2; ++i)
        {
            if (b == nullptr)
                return head;
            b = b->next;
        }

        ListNode* new_head = ReverseBetweenAB(a, b);
        a->next = swapPairs(b);

        return new_head;
    }

    // 辅函数，迭代反转区间 [a, b) 内链表，左闭右开
    ListNode* ReverseBetweenAB(ListNode* a, ListNode* b)
    {
        ListNode *pre = nullptr, *cur = a, *nxt = a;
        // 退出时 pre 就指向反转后的链表头节点
        while (cur != b)
        {
            // 记录后面的节点
            nxt = cur->next;
            // 逐个反转
            cur->next = pre;
            // 更新
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end

