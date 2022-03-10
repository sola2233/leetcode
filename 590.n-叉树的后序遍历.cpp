/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        traverse(root);
        return res;        
    }

    void traverse(Node* root)
    {
        // base case
        if (root == nullptr)
            return;

        // 递归遍历
        for (auto& child : root->children)
        {
            traverse(child);
        }
        res.push_back(root->val);
    }
};
// @lc code=end

