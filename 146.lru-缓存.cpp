/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
/** 
 * hash 可以在 o(1) 查找
 * list 可以在 o(1) 删除、插入
 * 所以结合使用，hashmap 存储 key 到双向链表节点的映射
 * 双向链表按照被使用的顺序存储了这些键值对
 * 靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的
 */
#include <unordered_map>
using namespace std;
// 双向链表结构体
struct DListNode {
    int key;
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    DListNode(int key_, int val_) : key(key_), val(val_), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    // 虚拟头尾节点
    DListNode* dummy_head;
    DListNode* dummy_tail;
    unordered_map<int, DListNode*> cache;
    int size_;
    int cap_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
        size_ = 0;
        // 连接头尾
        dummy_head = new DListNode();
        dummy_tail = new DListNode();
        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;
        // 最近使用的移动到头部
        DListNode* node = cache[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // 已经存在
        if (cache.count(key))
        {
            // 最近使用的移动到头部
            DListNode* node = cache[key];
            node->val = value;
            moveToHead(cache[key]);
        }
        // 不存在
        else
        {
            DListNode* node = new DListNode(key, value);
            // 头部插入，同时构建 hash 映射，增加 size
            addToHead(node);
            cache[key] = node;
            size_++;
            if (size_ > cap_)
            {
                // 超出容量就删除
                DListNode* last = removeLast();
                // 要同时删除节点和 hash 映射，减少 size
                cache.erase(last->key);
                delete last;
                size_--;
            }
        }
    }
private:
    /** 提供四个双向链表的操作 */
    // 每个新的节点添加到链表头部，头插法
    void addToHead(DListNode* node)
    {
        node->next = dummy_head->next;
        node->prev = dummy_head;
        dummy_head->next->prev = node;
        dummy_head->next = node;
    }

    // 删除节点
    void removeNode(DListNode* node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // 删除最后一个节点，最久未使用，返回 node 是为了删除 hashmap 中的映射
    DListNode* removeLast()
    {
        DListNode* node = dummy_tail->prev;
        removeNode(node);
        return node;
    }

    // 最近使用的节点移动到头部
    void moveToHead(DListNode* node)
    {
        removeNode(node);
        addToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

