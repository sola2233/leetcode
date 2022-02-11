/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/** 
 * 翻转链表
 * 方法1：迭代
 * 方法2：递归，效率低一点
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
    // 方法2，递归，递归函数定义是返回翻转链表的首节点指针，即原先的尾节点指针
    // ListNode* reverseList(ListNode* head) {
    //     // base case，head 为空是负例，head 只有一个节点是我们的递归基
    //     if (head == nullptr || head->next == nullptr)
    //         return head;
    //     // 递归翻转 head->next 子链，并返回子链翻转后的首节点指针 last
    //     ListNode* last = reverseList(head->next);
    //     // 当前节点 head 作为后继翻转子链的尾节点
    //     head->next->next = head; // 子链尾节点 next 指向当前节点
    //     head->next = nullptr;    // 当前节点 next 指向 nullptr

    //     return last; // 返回 last，不是 head
    // }

    // 方法1，迭代
    ListNode* reverseList(ListNode* head) {
        // 遍历链表
        ListNode* pre = nullptr, *cur = head, *nxt = head;
        while (cur != nullptr)
        {
            // 记录 cur 的后继
            nxt = cur->next;
            // 逐个节点反转
            cur->next = pre;
            // 更新节点
            pre = cur;
            cur = nxt;
        }

        return pre;
    }
};
// @lc code=end

