/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/** 
 * bst，bst框架
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
    // 递归函数，在以 root 为根的 bst 中删除 key，返回新的 bst 根节点
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if (root == nullptr)
            return root;
        
        // 去左子树删
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        // 去右子树删
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // 找到删除，返回删除后子树的根节点
        if (root->val == key)
        {
            // 1.包含了 root 没有子节点和只有一个子节点两种情况
            if (root->left == nullptr)  return root->right;
            if (root->right == nullptr) return root->left;
            // 2.root 有两个子节点的情况，此时把右子树中的最小值放到 root 处
            // 找到 root 右子树的最小节点，即 root 的直接后继
            TreeNode* min_node = GetMinNode(root->right);
            // 去右子树中删除 min_node，实际上就变成了第一种删除情况：待删除节点没有子节点
            root->right = deleteNode(root->right, min_node->val);
            // 交换 min_node 和 root
            min_node->left = root->left;
            min_node->right = root->right;
            // 令 root 指向新的子树根节点就行了，直接返回，会在上一层递归中接到树上
            root = min_node;
            
            // 如果要 delete 节点的话，每种分支里面都要 delete 节点
        }
        return root;
    }

    TreeNode* GetMinNode(TreeNode* root)
    {
        while (root->left != nullptr)
            root = root->left;
        return new TreeNode(root->val);
    }
};
// @lc code=end

