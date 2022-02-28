/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */

// @lc code=start
/** 
 * 方法1.中序遍历 + 双指针
 * 方法2.中序遍历 + hashset
 * 方法3.中序遍历 + hashset，不用储存中序遍历序列了，直接存到 hashset 里
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
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> inorder;
    unordered_set<int> hashset;
    bool findTarget(TreeNode* root, int k) {
        // 方法1.双指针
        // int left = 0, right = inorder.size() - 1;
        // while (left < right)
        // {
        //     int sum = inorder[left] + inorder[right];
        //     if (sum > k)
        //         right--;
        //     else if (sum < k)
        //         left++;
        //     else
        //         return true;
        // }
        
        // 方法2.hashset
        // for (int i = 0; i < inorder.size(); ++i)
        // {
        //     if (hashset.count(k - inorder[i]))
        //         return true;
        //     hashset.insert(inorder[i]);
        // }

        return traverse(root, k);
    }

    bool traverse(TreeNode* root, const int& k)
    {
        // base case
        if (root == nullptr)
            return false;
        if (hashset.count(k - root->val))
            return true;
        // 加入 hashset
        hashset.insert(root->val);

        return traverse(root->left, k) || traverse(root->right, k);
    }
};
// @lc code=end

