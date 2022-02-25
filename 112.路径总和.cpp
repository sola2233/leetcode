/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
/** 
 * 遍历，其实就是回溯法
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
    // 方法1.全部遍历
    // int sum = 0;
    // bool has_target = false;
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     // 负例
    //     if (root == nullptr)
    //         return false;
    //     sum += root->val;
    //     traverse(root, targetSum);

    //     return has_target;
    // }

    // void traverse(TreeNode* root, int target)
    // {
    //     // base case 找到叶子节点，不能用空节点，因为路径和必须是到叶子，空节点有案例通不过
    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         if (sum == target)
    //             has_target = true;
    //         return;
    //     }
        
    //     // base case 变了，这里要保证递归函数的参数节点不为空
    //     if (root->left != nullptr)
    //     {
    //         sum += root->left->val;
    //         traverse(root->left, target);
    //         sum -= root->left->val;
    //     }
    //     if (root->right != nullptr)
    //     {
    //         sum += root->right->val;
    //         traverse(root->right, target);
    //         sum -= root->right->val;
    //     }
    // }

    // 方法2.递归函数加返回值，不用全部遍历
    // int sum = 0;
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     // 负例
    //     if (root == nullptr)
    //         return false;

    //     sum += root->val;

    //     return traverse(root, targetSum);
    // }

    // bool traverse(TreeNode* root, int target)
    // {
    //     // base case 找到叶子节点，不能用空节点，因为路径和必须是到叶子，空节点有案例通不过
    //     if (root->left == nullptr && root->right == nullptr && sum == target)
    //         return true;
    //     if (root->left == nullptr && root->right == nullptr && sum != target)
    //         return false; // 不等于 target 时，遇到叶子节点直接返回

    //     // base case 变了，这里要保证递归函数的参数节点不为空
    //     if (root->left != nullptr)
    //     {
    //         sum += root->left->val; // 递归，处理节点;
    //         if (traverse(root->left, target))
    //             return true;
    //         sum -= root->left->val; // 回溯，撤销处理结果
    //     }
    //     if (root->right != nullptr)
    //     {
    //         sum += root->right->val; // 递归，处理节点;
    //         if (traverse(root->right, target))
    //             return true;
    //         sum -= root->right->val; // 回溯，撤销处理结果
    //     }

    //     return false;
    // }

    // 方法3.递归子树
    bool hasPathSum(TreeNode* root, int targetSum) {
        // base case
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
            return true;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// @lc code=end

