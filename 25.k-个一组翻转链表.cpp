/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/** 
 * 链表反转
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
class Solution {
public:
    // 递归
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 区间 [a, b) 包含 k 个待反转元素，先找到 a 和 b
        ListNode *a, *b;
        a = b = head;
        for (int i = 0; i < k; ++i)
        {
            // base case，最后不足 k 个节点时，不需要反转
            if (b == nullptr)
                return a;
            b = b->next;
        }

        // 反转 [a, b) 区间，返回新的头节点
        ListNode* new_head = reverse(a, b);
        // 递归反转后续链表，并且拼接起来
        // a 指向原来的头节点，也就是现在的尾节点，将下一组反转子链表的头节点接到 a 后面
        a->next = reverseKGroup(b, k);

        return new_head;
    }

    // 辅函数，迭代反转区间内链表，左闭右开，链表反转后，尾节点后是 nullptr，如果 pre 初始化为 b，则尾节点后是b
    ListNode* reverse(ListNode* a, ListNode* b)
    {
        ListNode* pre = nullptr, *cur = a, *nxt = a;
        // 反转链表
        while (cur != b)
        {
            // 先记录 cur 的 next 节点，因为需要逐个反转 cur，不记录就找不到 next 了
            nxt = cur->next;
            // 逐个节点反转
            cur->next = pre;
            // 更新指针位置
            pre = cur;
            cur = nxt;
        }
        // 返回反转后的头节点
        return pre;
    }
};
// @lc code=end

