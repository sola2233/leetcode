/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *nxt) : val(x), next(nxt) {}
    };

    MyLinkedList() {
        dummy_ = new ListNode();
        size_ = 0;
    }
    
    int get(int index) {
        // 负例
        if (index < 0 || index >= size_)
            return -1;
        
        ListNode* cur = dummy_;
        // 找到 index 前面一个节点
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* head = new ListNode(val);
        head->next = dummy_->next;
        dummy_->next = head;
        // 更新大小
        size_++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummy_;
        // 找到最后一个节点
        while (cur->next != nullptr)
            cur = cur->next;
        // 插入
        ListNode* tail = new ListNode(val);
        cur->next = tail;
        // 更新大小
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size_)
            return;
        if (index == size_)
        {
            addAtTail(val);
            return;
        }
        if (index <= 0)
        {
            addAtHead(val);
            return;
        }
        // 找到 index 前面一个节点
        ListNode* cur = dummy_;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        // 插入
        ListNode* node = new ListNode(val);
        node->next = cur->next;
        cur->next = node;
        // 更新大小
        size_++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size_)
            return;
        ListNode* cur = dummy_;
        // 找到 index 前面一个节点
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        // 删除
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // 更新大小
        size_--;
    }
private:
    int size_;
    ListNode* dummy_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

