/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/** 
 * 二叉树问题，递归转迭代
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
    stack<TreeNode*> stk;
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        // 左侧链入栈
        pushLeftBranch(root);
        // 记录上一个出栈元素，为 visited 指向元素分配一块内存，让其不为空
        TreeNode* visited = new TreeNode();
        while (!stk.empty())
        {
            TreeNode* p = stk.top();

            // 左子树遍历完了
            if ((p->left == nullptr || p->left == visited) && p->right != visited)
            {
                // 中序位置
                // 右子树左侧链入栈
                pushLeftBranch(p->right);
            }

            // 右子树遍历完了
            if (p->right == nullptr || p->right == visited)
            {
                // 后序位置
                // p 的左右子树访问完了，出栈，记录 p
                visited = p;
                stk.pop();
            }
        }

        return res;
    }

    void pushLeftBranch(TreeNode* p)
    {
        while (p != nullptr)
        {
            // 前序位置
            res.push_back(p->val);
            // 入栈
            stk.push(p);
            p = p->left;    
        }
    }
};
// @lc code=end

