/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

// @lc code=start
/** 
 * 二叉树问题，递归
 * 递归 + hash + 序列化
 * 这里根据题意每个节点需要知道以自己为根的子树的形态，所以用后序遍历
 * 用字符串记录每个节点的后序遍历序列
 * 用 hashtable 储存序列，便于查询是否重复，同时为了不放入重复的节点，用 hashmap 而不是 hashset，
 * 只有第一次遇到重复结构才插入返回的 vector 中
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
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 备忘录，记录所有子树结构和出现次数
    unordered_map<string, int> memo;
    // 存放重复的子树根节点
    vector<TreeNode*> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        traverse(root);

        return res;
    }

    // 递归函数，返回每个节点的后序遍历序列，用字符串形式
    string traverse(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return string("#");
        
        // 递归子树
        string left = traverse(root->left);
        string right = traverse(root->right);

        // 后序位置处理根节点 root
        string subtree = left + "," + right + "," + to_string(root->val);

        // 存入备忘录
        memo[subtree]++;
        // 查看是否重复
        if (memo[subtree] == 2)
            res.push_back(root);

        return subtree;
    }
};
// @lc code=end

