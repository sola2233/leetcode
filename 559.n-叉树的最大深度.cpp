/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/** 
 * 同二叉树的最大深度问题，有三种解法
 * 递归两种
 * 迭代一种：层次遍历
 */
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
#include <algorithm>
using namespace std;
class Solution {
public:
    // 递归，分解子问题，不能用遍历方法，因为多叉树相当于没有为空的 外部节点
    // 所以不能和二叉树问题一样在 base case里更新深度
    int maxDepth(Node* root) {
        // base case
        if (root == nullptr)
            return 0;
        
        // 递归子树
        int depth = 0;
        for (auto& child : root->children)
            depth = max(depth, maxDepth(child));

        return depth + 1;
    }
};
// @lc code=end

