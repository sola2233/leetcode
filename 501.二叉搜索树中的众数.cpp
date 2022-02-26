/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/** 
 * 方法1.遍历，用 hashmap 记录频次
 * 方法2.利用中序遍历有序的特点，一次遍历就能完成
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
#include <algorithm>
using namespace std;
class Solution {
public:
    TreeNode* pre_node; // 记录遍历中上一个节点
    int count; // 记录当前节点出现频次
    int max_count; // 记录最多出现频次
    vector<int> res; // 返回值

    vector<int> findMode(TreeNode* root) {
        pre_node = nullptr;
        count = 0;
        max_count = 0;

        traverse(root);

        return res;
    }

    // 递归遍历，中序遍历
    void traverse(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        traverse(root->left);
        // 初始化第一个节点
        if (pre_node == nullptr)
        {
            count = 1;
            max_count = 1;
        }
        // 一样的节点
        else if (pre_node != nullptr && root->val == pre_node->val)
            count++;
        // 出现不一样的节点
        else if (pre_node != nullptr && root->val != pre_node->val)
            count = 1;

        // 存放一个结果
        if (count == max_count)
            res.push_back(root->val);
        // 更新最大频次，删除前面的结果，这一步也会把重复的元素删掉
        if (count > max_count)
        {
            max_count = count;
            res.clear();
            res.push_back(root->val);
        }

        // 更新 pre node，千万别忘了
        pre_node = root;

        traverse(root->right);
    }
};
// @lc code=end

