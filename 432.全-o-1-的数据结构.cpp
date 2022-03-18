/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start
/** 
 * 双向链表 + hash
 */
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class AllOne {
// 链表节点
struct ListNode {
    // 储存相同计数的所有键值
    unordered_set<string> keys;
    // 储存键值计数
    int cnt;
    ListNode* prev;
    ListNode* next;
    ListNode() : cnt(-1), prev(nullptr), next(nullptr) {}
    ListNode(string key, int n) : cnt(n)
    {
        keys.insert(key);
    }
};
public:
    AllOne() {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        // 键值已经存在
        if (key2node.count(key))
        {
            ListNode* cur = key2node[key];
            ListNode* nxt = cur->next;
            // 原来节点 cur 中删除 key
            cur->keys.erase(key);
            // cnt + 1 节点存在
            if (nxt->cnt == cur->cnt + 1)
            {
                nxt->keys.insert(key);
                // 修改映射
                key2node[key] = nxt;
            }
            // cnt + 1 节点不存在
            else
            {
                // 插入新节点
                ListNode* node = new ListNode(key, cur->cnt + 1);
                insertNode(node, nxt);
                // 修改映射
                key2node[key] = node;
            }
            // 最后还要判断原来的节点 cur 中是否还有元素 key
            if (cur->keys.empty())
                deleteNode(cur);
        }
        // 键值不存在
        else
        {
            // cnt == 1 节点存在
            if (head->next->cnt == 1)
            {
                head->next->keys.insert(key);
                // 修改映射
                key2node[key] = head->next;
            }
            // cnt == 1 节点不存在
            else
            {
                ListNode* node = new ListNode(key, 1);
                insertNode(node, head->next);
                // 修改映射
                key2node[key] = node;           
            }
        }
    }
    
    void dec(string key) {
        // 减少计数保证当前键值是存在的
        ListNode* cur = key2node[key];
        ListNode* prev = cur->prev;
        // cnt - 1 == 0
        if (cur->cnt == 1)
        {
            cur->keys.erase(key);
            // 修改映射
            key2node.erase(key);
        }
        // cnt - 1 节点已存在
        else if (prev->cnt == cur->cnt - 1)
        {
            cur->keys.erase(key);
            prev->keys.insert(key);
            // 修改映射
            key2node[key] = prev;
        }
        // cnt - 1 节点不存在
        else
        {
            ListNode* node = new ListNode(key, cur->cnt - 1);
            insertNode(node, cur);
            // 修改映射
            key2node[key] = node;
        }
        // 最后还要判断原来的节点 cur 中是否还有元素 key
        if (cur->keys.empty())
            deleteNode(cur);
    }
    
    string getMaxKey() {
        if (!tail->prev->keys.empty())
            return *(tail->prev->keys.begin());
        return "";
    }
    
    string getMinKey() {
        if (!head->next->keys.empty())
            return *(head->next->keys.begin());
        return "";
    }

    // 将 node 插入到 nxt 前面
    void insertNode(ListNode* node, ListNode* next)
    {
        ListNode* prev = next->prev;
        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
    }

    // 删除 node 节点
    void deleteNode(ListNode* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete(node);
    }

private:
    // 字符串到链表节点的映射
    unordered_map<string, ListNode*> key2node;
    // 虚拟头尾节点，升序双向链表
    ListNode* head, *tail;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

