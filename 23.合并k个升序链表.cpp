/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/** 
 * 链表问题，类似合并两个有序链表
 * 此处的不同在于 k 个链表的头结点选出最小值，可以建立一个小顶堆，即利用优先级队列
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
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // 小顶堆，仿函数
    struct comp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 优先队列，组织成小顶堆
        priority_queue<ListNode *, vector<ListNode*>, comp> pq;
        // 虚拟头结点
        ListNode * dummy = new ListNode(), *p = dummy;
        // 建堆，将 k 个链表头结点加入 pq
        for (auto head : lists)
        {
            if (head != nullptr)
                pq.push(head);
        }
        // 依次拿出最小的节点
        while (!pq.empty())
        {
            // 取出堆顶
            ListNode *cur = pq.top();
            pq.pop();
            p->next = cur;
            // 取出节点的后继节点加入 pq
            if (cur->next)
                pq.push(cur->next);
            // p 指针不断前进
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

