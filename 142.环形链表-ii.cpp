/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/** 
 * 双指针
 * 对于链表找环路有一个通用解法：快慢指针
 * 给定两个指针 slow 和 fast，起始位置在链表的开头。
 * 每次 fast 前进两步，slow 前进一步。如果 fast 可以走到尽头，那么说明没有环路；
 * 如果 fast 可以无限走下去，那么说明一定有环路，且一定存在一个时刻 slow 和 fast 相遇。
 * 当 slow 和 fast 第一次相遇时，将 fast 重新移动到链表头，并让 slow 和 fast 每次都前进一步。
 * 当 slow 和 fast 第二次相遇时，相遇的节点即为环路的开始点。
 * [解释为什么快慢指针第二次相遇在环路开始点]
 * (https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/)
 */
#include <stddef.h> /** NULL */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        do
        {
            /** 链表没有环路直接退出 */
            if(fast == nullptr || fast->next == nullptr)
                return nullptr;
            /** 快慢指针 */
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        /** 令fast移动到链表头 */
        fast = head;
        /** 第二次相遇即为环路开始点 */
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
// @lc code=end

