/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/** 
 * 链表问题，常用双指针
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 虚拟头节点
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;
        // 其实可以省略，因为 list1 和 list2 就是指针
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        // 循环遍历两个有序链表
        while (p1 != nullptr && p2 != nullptr)
        {
            // 将较小的节点接到 p 尾端
            if (p1->val < p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            // p 指针不断前进
            p = p->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;

        return dummy->next;
    }
};
// @lc code=end

