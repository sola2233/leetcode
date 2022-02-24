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
        ListNode *a = headA, *b = headB;

        // 同样可以覆盖不想交的情况，此时 a = b = nullptr
        while (a != b)
        {
            /** 
             * 注意比较的是 a 而不是 a->next
             * 如果比较 next，且没有相交，就会无限循环
             * 如果比较 a，则会先比较 a 和 b 是否相等，再比较 a 和 nullptr
             */
            // 走一步，如果 a 走到 A 尾端，则转到 B
            if (a == nullptr)
                a = headB;
            else
                a = a->next;
            // 走一步，如果 b 走到 B 尾端，则转到 A
            if (b == nullptr)
                b = headA;
            else
                b = b->next;
        }

        return a;
    }
};
// @lc code=end

