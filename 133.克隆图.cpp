/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/** 
 * dfs
 */
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 哈希表，存储已经拷贝的节点
    unordered_map<int, Node*> created;
    // dfs 遍历
    Node* cloneGraph(Node* node) {
        // 负例，空的图
        if (node == nullptr)
            return node;
        // 节点已经创建，直接返回
        if (created.count(node->val))
            return created[node->val];
        // 节点未拷贝，先创建节点，再递归添加邻居
        Node* root = new Node(node->val);
        created[node->val] = root; // 哈希表存储
        // 递归添加邻居
        for (auto neigh : node->neighbors)
        {
            root->neighbors.push_back(cloneGraph(neigh));
        }
        return root;
    }

};
// @lc code=end

