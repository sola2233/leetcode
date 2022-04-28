/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
 */

// @lc code=start
/** 
 * bst
 * 方法1.递归，递归函数返回 root
 * 方法2.迭代
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
class Solution {
public:
#if 1   // 递归
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // base case，找到插入位置
        if (root == nullptr)
            return new TreeNode(val);

        // 去左子树找
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        // 去右子树找
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        // 不会存在相等元素，所以 root->val == val 不存在，最后只会找到 base case
        return root;
    }
#endif

#if 0   // 迭代
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 负例
        if (root == nullptr)
            return new TreeNode(val);

        // pre 保存 cur 的父节点
        TreeNode* pre = nullptr, *cur = root;
        while (cur)
        {
            pre = cur;
            if (val < cur->val)
                cur = cur->left;
            else if (val > cur->val)
                cur = cur->right;
        }
        
        // 合适位置插入
        if (val < pre->val)
            pre->left = new TreeNode(val);
        else if (val > pre->val)
            pre->right = new TreeNode(val);
        
        return root;
    }
#endif
};
// @lc code=end

