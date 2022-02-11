/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/** 
 * 链表，回文
 * 方法1.递归遍历链表，后序位置比较，即可比较头尾，但是时间和空间都是 o(n)
 * 方法2.快慢指针找中点，反转后半部分，比较前半和后半，时间 o(n)，空间 o(1)
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
    bool isPalindrome(ListNode* head) {
        // 快慢指针
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 链表长度为奇数时，slow 指向中间节点，向后移动一个
        if (fast != nullptr)
            slow = slow->next;
        // 反转后半部分
        ListNode *left = head;
        ListNode *right = reverse(slow);
        // 比较前半和后半字符是否相等
        while (right != nullptr)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }

    // 反转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode *pre = nullptr, *cur = head, *nxt = head;
        // 反转链表
        while (cur != nullptr)
        {
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

