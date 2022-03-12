/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Trie {
public:
    struct TreeNode {
        bool is_node;
        // unordered_map<char, TreeNode*> children;
        // vector 可以代替 hashmap
        vector<TreeNode*> children;
        TreeNode() : is_node(false), children(26) {}
        TreeNode(bool is_node) : is_node(is_node), children(26) {}
    };

    TreeNode* root;

    Trie() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* p = root;
        for (char ch : word)
        {
            ch -= 'a';
            if (p->children[ch] == nullptr)
                p->children[ch] = new TreeNode();
            p = p->children[ch];           
        }
        p->is_node = true;
    }
    
    bool search(string word) {
        TreeNode* p = root;
        for (char ch : word)
        {
            ch -= 'a';
            if (p->children[ch] != nullptr)
                p = p->children[ch];
            else
                return false;    
        }
        return p->is_node;
    }
    
    bool startsWith(string prefix) {
        TreeNode* p = root;
        for (char ch : prefix)
        {
            ch -= 'a';
            if (p->children[ch] != nullptr)
                p = p->children[ch];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

