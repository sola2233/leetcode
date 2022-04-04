/** 
 * https://www.nowcoder.com/practice/f96cd47e812842269058d483a11ced4f?tpId=37&tqId=21271&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26judgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=3&tags=&title=
 * 从单向链表中删除指定值的节点
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode() : val(-1), next(nullptr) {}
    ListNode(int val_, ListNode* next_) : val(val_), next(next_) {}
};

int main()
{
    int n, head_val;
    cin >> n >> head_val;
    // 构造链表
    ListNode* dummy = new ListNode();
    ListNode* head = new ListNode(head_val, nullptr);
    dummy->next = head;
    for (int i = 0; i < n - 1; ++i)
    {
        int cur_val, prev_val;
        cin >> cur_val >> prev_val;
        // 找到 prev
        ListNode* p = dummy;
        while (p->val != prev_val)
            p = p->next;
        ListNode* cur = new ListNode(cur_val, p->next);
        p->next = cur;
    }
    // 删除指定节点
    int del_val;
    cin >> del_val;
    ListNode* p = dummy, *prev;
    while (p != nullptr)
    {
        // 删除节点
        if (p->val == del_val)
        {
            ListNode* tmp = p;
            prev->next = p->next;
            p = p->next;
            delete tmp;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
    for (ListNode* p = dummy->next; p != nullptr; p = p->next)
        cout << p->val << " ";
    cout << endl;
    
    return 0;
}