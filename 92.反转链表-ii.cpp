/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/** 
 * 翻转链表
 * 方法1，迭代
 * 方法2，递归
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    // 方法2，递归
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     // base case
    //     if (left == 1)
    //         return reverseN(head, right);
        
    //     ListNode* last = reverseBetween(head->next, left-1, right-1);

    //     head->next = last;

    //     return head; // 返回 head，因为反转的部分在中间
    // }

    // // 辅函数，翻转链表前 n 个节点
    // ListNode* succ = nullptr;
    // ListNode* reverseN(ListNode* head, int n)
    // {
    //     // base case
    //     if (n == 1)
    //     {
    //         // 此时 head 就是整个链表中第 n 个节点
    //         succ = head->next; // 记录后继 next，为了后面 head 能连上
    //         return head;
    //     }
    //     // 递归翻转 head->next 前 n-1 个节点
    //     ListNode* last = reverseN(head->next, n-1);

    //     head->next->next = head; // 翻转头结点 head 变为尾节点
    //     head->next = succ; // 让反转之后的 head 节点和后面的节点连起来

    //     return last; // 返回 last，不是 head
    // }

    // 方法1，迭代，两次遍历
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 虚拟头节点
        ListNode *dummy = new ListNode(0, head);
        // 左开右开，利用 dummy 获得待反转部分前一个节点
        ListNode *a = dummy, *b = head;
        for (int i = 0; i < right; ++i)
        {
            if (i < left - 1)
                a = a->next;
            if (i <= right - 1)
                b = b->next;
        }

        // 反转链表
        ListNode *pre = b, *cur = a->next, *nxt = a->next;
        while (cur != b)
        {
            nxt = cur->next;
            // 逐个节点反转
            cur->next = pre;
            // 更新节点
            pre = cur;
            cur = nxt;
        }
        // 前面部分和反转部分拼接
        a->next = pre;

        ListNode *res = dummy->next;
        delete dummy;
        // 不能返回head，因为 head 不一定是现在的头节点
        return res;
    }

    // 方法1，迭代，一次遍历
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     // 虚拟头节点
    //     ListNode* dummy = new ListNode(0, head);
    //     // 移动 head 到 left
    //     ListNode* pre = dummy; // 指向待翻转区域前一个节点
    //     for (int i = 0; i < left-1; ++i)
    //         pre = pre->next;
    //     head = pre->next; // head 永远指向待翻转区域第一个节点 left，但是后继 next 会改变
    //     // 翻转部分链表，在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置
    //     for (int i = 0; i < right - left; ++i)
    //     {
    //         // 记录 head 的后继 succ，每次循环都把 succ 移到翻转部分起始位置
    //         ListNode* succ = head->next;
    //         // succ 从 head 后面移出
    //         head->next = succ->next;
    //         // succ 移到 翻转部分起始位置
    //         succ->next = pre->next;
    //         pre->next = succ;
    //     }
    //     // 循环结束后 head 就移动到了链表的 right 位置

    //     ListNode* res = dummy->next;
    //     delete dummy;

    //     return res;
    // }
};
// @lc code=end

