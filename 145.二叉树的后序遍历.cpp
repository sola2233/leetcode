/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/** 
 * 二叉树前、中、后序遍历跌代写法，用栈模拟递归，主要是找到左子树遍历完的位置和右子树遍历完的位置：
 * 1.栈顶元素 p 左子树遍历完的位置：
 *   左子树 left 为空或者 left 是上一个出栈的节点 visited，且右子树 right 不等于上一个出栈节点，
 *   因为右子树 right 遍历完也有一种情况是左子树 left 为空。
 * 2.栈顶元素 p 右子树遍历完的位置：
 *   右子树 right 为空或者 right 是上一个出栈的节点 visited。
 * 
 * 前序位置：节点 p 入栈前的位置
 * 中序位置：节点 p 左子树遍历完的位置
 * 后序位置：节点 p 右子树遍历完的位置，因为入栈顺序是先左子树，后右子树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    // 用栈模拟递归
    stack<TreeNode*> stk;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        // 左侧链全部入栈
        pushLeftBranch(root);
        // visited 代表上一个遍历完的根节点，即上一次出栈的节点
        TreeNode* visited = new TreeNode();
        while (!stk.empty())
        {
            // 获取栈顶元素
            TreeNode* p = stk.top();

            // p 的左子树遍历完了
            if ((p->left == nullptr || p->left == visited) && p->right != visited)
            {
                // 中序位置，省略
                // 遍历 p 的右子树，右侧节点全部入栈
                pushLeftBranch(p->right);
            }

            // p 的右子树遍历完了
            if (p->right == nullptr || p->right == visited)
            {
                // 后序位置
                res.push_back(p->val);
                // 以 p 为根的树遍历完了，出栈，记录上一次遍历的节点
                visited = p;
                stk.pop();
            }
        }

        return res;
    }

    // root 左侧链节点入栈
    void pushLeftBranch(TreeNode* root)
    {
        while (root != nullptr)
        {
            // 前序位置，省略
            stk.push(root);
            root = root->left;
        }
    }
};
// @lc code=end

