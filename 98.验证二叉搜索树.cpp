/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/** 
 * bst
 * 方法1.递归子问题，每个 root 处检查是否满足 bst，返回 bool 值
 *      这种解法还是有点模糊，不太理解其中的 min 和 max
 * 方法2.利用中序遍历
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
#if 1   // 利用中序遍历
    // 方法2，利用中序遍历
    bool isValidBST(TreeNode* root) {
        bool res = traverse(root);

        return res;
    }

    // 用一个辅助的指针指向上一个遍历节点，可以避免初始化最小值并比较（节点可能取到 int 最小值）
    TreeNode* pre_node = nullptr;
    // 辅函数，中序遍历
    bool traverse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return true;
        
        // 递归
        int left = traverse(root->left);
        // 中序位置
        if (pre_node != nullptr && root->val <= pre_node->val)
            return false;
        pre_node = root;
        int right = traverse(root->right);

        return left && right;
    }
#endif

#if 0   // 递归
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

    // 方法1，递归，通过辅助函数，增加参数列表，将约束传递给子节点，这里是自顶向下比较
    // 所以是前序，比较了每个节点 root 和参数传递的范围，
    // 即每个以 root 为根的子树节点必须满足 min < root->val < max
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max)
    {
        // base case
        if (root == nullptr)
            return true;
        
        // 比较 root 节点，检查 root 节点是否满足
        if (min != nullptr && root->val <= min->val)
            return false;
        if (max != nullptr && root->val >= max->val)
            return false;

        // 递归左右子树，检查左右子树是否满足
        // root 的左子树的最大值是 root
        bool left = isValidBST(root->left, min, root);
        // root 的右子树的最小值是 root
        bool right = isValidBST(root->right, root, max);

        return left && right;
    }
#endif
};
// @lc code=end

