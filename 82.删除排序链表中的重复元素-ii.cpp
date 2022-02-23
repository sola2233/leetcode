/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/** 
 * 链表，快慢指针，和 83 题有一点不同，这题需要使用虚拟节点
 * 始终都是比较的 cur->next 和 cur->next->next，所以不用两个指针
 * 选择 cur->next 是因为要删除所有重复元素，一个不能留
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
        ListNode* dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            // 遇到重复元素
            if (cur->next->val == cur->next->next->val)
            {
                // x 为目前重复元素的值 val
                int x = cur->next->val;
                // cur->next 的值不再是 x，说明删光了所有重复元素，要加一个非空判断
                while (cur->next != nullptr && cur->next->val == x)
                    cur->next = cur->next->next;
            }
            // 不重复的元素
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

