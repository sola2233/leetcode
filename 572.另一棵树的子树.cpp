/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start
/** 
 * 小小的简单题卧虎藏龙
 * 方法1.后序遍历序列化(因为要找以某个节点为根的子树，所以后序比较好) + 比较
 * 方法2.序列化 + kmp
 * 方法3.判断一棵树与另一棵树本身或子树是否相等，与 100 题相同
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
#include <string>
using namespace std;
class Solution {
public:
#if 0   // 方法1.后序遍历序列化 + 比较
    
    bool is_subtree = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 序列化 subRoot
        string pattern = traverseSubTree(subRoot);
        // 遍历
        traverse(root, pattern);

        return is_subtree;
    }

    // 递归遍历+回溯，序列化以每个节点为根的子树，比较两个序列
    string traverse(TreeNode* root, string& pattern)
    {
        // base case
        if (root == nullptr)
        {
            return "#,";
        }

        string left = traverse(root->left, pattern);
        string right = traverse(root->right, pattern);

        string path = left + right + to_string(root->val) + ",";
        if (path == pattern)
            is_subtree = true;

        return path;
    }

    // 递归遍历+回溯，序列化以每个节点为根的子树，比较两个序列
    string traverseSubTree(TreeNode* root)
    {
        // base case
        if (root == nullptr)
        {
            return "#,";
        }

        string left = traverseSubTree(root->left);
        string right = traverseSubTree(root->right);

        string path = left + right + to_string(root->val) + ",";

        return path;
    }
#endif

    // 方法2.100题判断两棵树是否相同
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        // 如果要检查的子树为空，那么不用查了，肯定对的
        if (subRoot == nullptr)
            return true;
        // 如果要检查的子树不空，但root是空的，那也不用查了，错的。
        if (root == nullptr)
            return false;

        // 要么是它本身，要么是它左子树，要么是它的右子树
        // 判断两棵树本身是否相同
        bool is_same = isSameTree(root, subRoot);
        // 递归判断子树是否相同
        bool is_subtree_left = isSubtree(root->left, subRoot);
        bool is_subtree_right = isSubtree(root->right, subRoot);

        bool is_subtree = is_same || is_subtree_left || is_subtree_right;
        return is_subtree;
    }

    // 递归函数，递归遍历
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        // 如果两个都为空
        if (p == nullptr && q == nullptr)
            return true;
        // 如果只有一个为空
        else if (p == nullptr || q == nullptr)
            return false;
        // 如果两个都不空，结点值也不同，那直接返回false
        else if (p->val != q->val)
            return false;

        // 如果现在结点值和子树结点值相同，再分别检查两个的左右孩子
        // 递归遍历子树
        bool is_same_left = isSameTree(p->left, q->left);
        bool is_same_right = isSameTree(p->right, q->right);

        return is_same_left && is_same_right;
    }
};
// @lc code=end

