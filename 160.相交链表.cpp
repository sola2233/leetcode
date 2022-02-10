/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/** 
 * 链表问题，本题用双指针解决，虽然可以通过 hashtable，但是需要额外 o(m+n) 的空间
 * 此处两个链表长度不等，为了找到相交节点，需要两个指针同步前进
 * 考虑将两个链表接在一起，一个遍历 A+B，一个遍历 B+A
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;

        // 同样可以覆盖不想交的情况，此时 p1 = p2 = nullptr
        while (p1 != p2)
        {
            // 走一步，如果 p1 走到 A 尾端，则转到 B
            if (p1 == nullptr)
                p1 = headB;
            else
                p1 = p1->next;
            // 走一步，如果 p2 走到 B 尾端，则转到 A
            if (p2 == nullptr)
                p2 = headA;
            else
                p2 = p2->next;
        }

        return p1;
    }
};
// @lc code=end

