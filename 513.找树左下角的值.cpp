/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */

// @lc code=start
/** 
 * 方法1.层次遍历
 * 方法2.递归遍历，不是递归子树了
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
    int depth = 0;
    int max_depth = -1; // -1 是为了让只有一个节点的树能比较成功，或者令 depth 初始为 1
    int max_depth_value;

    int findBottomLeftValue(TreeNode* root) {
        traverse(root);

        return max_depth_value;
    }

    void traverse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return;

        // 前序位置，找到一个叶子节点
        if (root->left == nullptr && root->right == nullptr)
        {
            // 最深的叶子节点
            if (depth > max_depth)
            {
                max_depth_value = root->val;
                max_depth = depth;
            }
        }
        
        depth++;
        traverse(root->left);
        depth--;
        // 这才是正规写法，就是有点蠢
        depth++;
        traverse(root->right);
        depth--;
    }
};
// @lc code=end

