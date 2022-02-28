/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
/** 
 * 方法1.构造函数中中序遍历扁平化 bst，值放到一个 vector 中，但是不满足题目的 o(h) 空间
 * 方法2.迭代遍历，利用栈
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
#include <stack>
using namespace std;
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        // 左侧链节点入栈
        pushLeftBranch(root);
    }
    
    int next() {
        // 如果按中序位置，后序位置的写法，栈最后不为空
        // 因为遍历完最大的那个节点(最右下角)后，最大节点出栈，此时栈中还有它的很多父节点
	    // 这些父节点在循环都应该执行后序位置出栈的过程
        // 但是因为 next 的单步调用，这个最后的出栈过程没有执行
        // 所以最后的 hasnext 判断会非空
        TreeNode* p = stk_.top();
        // 所以需要在中序位置让节点出栈
        stk_.pop();
        pushLeftBranch(p->right);

        return p->val;
    }
    
    bool hasNext() {
        return !stk_.empty();
    }

    // 左侧链节点入栈
    void pushLeftBranch(TreeNode* root)
    {
        while (root)
        {
            // 前序位置
            stk_.push(root);
            root = root->left;
        }
    }

private:
    stack<TreeNode*> stk_;
    TreeNode* visited_; // 指向上一个出栈的节点
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

