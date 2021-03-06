/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/** 
 * 方法1.遍历递归
 * 方法2.分解问题递归
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
#include <string>
using namespace std;
class Solution {
public:
#if 0   // 遍历，可以把 path 放到函数参数中，更简洁一点
    vector<string> res; // 存放结果
    vector<string> path; // 存放单个路径，选择vector是为了方便回溯

    vector<string> binaryTreePaths(TreeNode* root) {
        traverse(root);

        return res;
    }

    // 遍历
    void traverse(TreeNode* root)
    {
        // 这里 base 的条件是判断 root 的左右子树，所以需要先把 root 放到 path 中
        path.push_back(to_string(root->val));

        // base case，遇到叶子节点，而非外部节点
        if (root->left == nullptr && root->right == nullptr)
        {
            // 路径转化为字符串
            string one_path;
            int n = path.size();
            for (int i = 0; i < n - 1; ++i)
                one_path += path[i] + "->";
            one_path += path[n - 1]; // 最后一个后面没有箭头
            // 存放结果
            res.push_back(one_path);
            return;
        }

        // 递归遍历子节点，这里要判断是否为空
        if (root->left != nullptr)
        {
            traverse(root->left);
            // 回溯和递归要放到一起，回溯和递归是一一对应的，有一个递归就有一个回溯
            path.pop_back();
        }
        if (root->right != nullptr)
        {
            traverse(root->right);
            // 回溯和递归要放到一起，回溯和递归是一一对应的，有一个递归就有一个回溯
            path.pop_back();
        }
    }
#endif

#if 1   // 分解问题递归
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
            return {};
        
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);

        string node = to_string(root->val);
        for (string& s : left)
            res.push_back(node + "->" + s);
        for (string& s : right)
            res.push_back(node + "->" + s);

        if (res.empty())
            res.push_back(node);
        return res;
    }
#endif
};
// @lc code=end

