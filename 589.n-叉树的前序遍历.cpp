/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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
    vector<int> preorder(Node* root) {
        traverse(root);
        return res;
    }

    void traverse(Node* root)
    {
        // base case
        if (root == nullptr)
            return;

        res.push_back(root->val);
        // 递归遍历
        for (auto& child : root->children)
        {
            traverse(child);
        }
    }
};
// @lc code=end

