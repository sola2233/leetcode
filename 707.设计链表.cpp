/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
/** 
 * 方法1.单向链表
 * 方法2.双向链表
 */
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

// 方法2.双向链表
// class MyLinkedList {
//     struct ListNode {
//         int val;
//         ListNode* next;
//         ListNode* prev;
//         ListNode() : val(0), next(nullptr), prev(nullptr) {}
//         ListNode(int val_) : val(val_), next(nullptr), prev(nullptr) {}
//     };
// public:
//     MyLinkedList() {
//         head = new ListNode();
//         tail = new ListNode();
//         size = 0;
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int index) {
//         if (index < 0) return -1;
//         if (index >= size) return -1;
//         ListNode* cur = head;
//         for (int i = 0; i <= index; ++i)
//             cur = cur->next;
//         return cur->val;
//     }
    
//     void addAtHead(int val) {
//         ListNode* cur = new ListNode(val);
//         cur->next = head->next;
//         cur->prev = head;
//         head->next->prev = cur;
//         head->next = cur;
//         size++;
//     }
    
//     void addAtTail(int val) {
//         ListNode* cur = new ListNode(val);
//         cur->next = tail;
//         cur->prev = tail->prev;
//         tail->prev->next = cur;
//         tail->prev = cur;
//         size++;
//     }
    
//     void addAtIndex(int index, int val) {
//         if (index < 0)
//         {
//             addAtHead(val);
//             return;
//         }
//         if (index == size)
//         {
//             addAtTail(val);
//             return;
//         }
//         if (index > size) return;
//         ListNode* cur = head;
//         for (int i = 0; i <= index; ++i)
//             cur = cur->next;
//         ListNode* node = new ListNode(val);
//         node->next = cur;
//         node->prev = cur->prev;
//         cur->prev->next = node;
//         cur->prev = node;
//         size++;
//     }
    
//     void deleteAtIndex(int index) {
//         if (get(index) == -1)
//             return;
//         ListNode* cur = head;
//         for (int i = 0; i <= index; ++i)
//             cur = cur->next;
//         cur->next->prev = cur->prev;
//         cur->prev->next = cur->next;
//         delete cur;
//         size--; 
//     }
// private:
//     ListNode* head;
//     ListNode* tail;
//     int size;
// };

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

