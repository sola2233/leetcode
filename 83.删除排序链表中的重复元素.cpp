/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/** 
 * 链表，快慢指针
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 负例，这里要明确写出来，否则后面 slow 可能是空指针，没有 next 成员
        if (head == nullptr)
            return head;
        // 双指针
        ListNode *slow = head, *fast = head;
        while (fast != nullptr)
        {
            // [head, slow] 都是不重复的元素
            if (slow->val != fast->val)
            {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 断开 slow 后面的重复元素
        slow->next = nullptr;
        // 返回链表
        return head;
    }
};
// @lc code=end

