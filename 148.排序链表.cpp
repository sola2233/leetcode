/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
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
/** 
 * 147 的插入排序复杂度 o(n^2)，不合题意，考虑归并排序
 * 这题复杂
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }

    // 左闭右开区间
    ListNode* mergeSort(ListNode* start, ListNode* end)
    {
        // base case
        if (start == nullptr) // 区间为空
            return start;
        if (start->next == end) // 区间只有一个元素
        {
            start->next = nullptr; // 链表尾要断掉，不然后面跳不出循环
            return start;
        }
        // 双指针找中点
        ListNode *slow = start, *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 递归，分
        ListNode* left = mergeSort(start, slow);
        ListNode* right = mergeSort(slow, end);
        // 归并，治
        ListNode* dummy = new ListNode(0);
        ListNode *p1 = left, *p2 = right, *p3 = dummy;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                // 插入
                p3->next = p1;
                // 更新指针
                p3 = p3->next;
                p1 = p1->next;
            }
            else
            {
                // 插入
                p3->next = p2;
                // 更新指针
                p3 = p3->next;
                p2 = p2->next;
            }
        }
        while (p1 != nullptr)
        {
            // 插入
            p3->next = p1;
            // 更新指针
            p3 = p3->next;
            p1 = p1->next;
        }
        while (p2 != nullptr)
        {
            // 插入
            p3->next = p2;
            // 更新指针
            p3 = p3->next;
            p2 = p2->next;            
        }
        return dummy->next;
    }

};
// @lc code=end

