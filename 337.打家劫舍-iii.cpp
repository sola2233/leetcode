/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/** 
 * dp，为什么这么像 dfs 呢？而且很奇怪，方法1更快
 * 状态：节点 root
 * 选择：节点的变化，偷不偷入口 root
 * dp[root][0]：不偷节点 root
 * dp[root][1]：偷节点 root
 * 状态转移方程：root 有两个子节点 left 和 right
 * 1.不偷 root，则子节点 left 和 right 可偷可不偷
 *   dp[root][0] = max(dp[left][0], dp[left][1]) + max(dp[right][0], dp[right][1])
 * 2.偷 root，则子节点 left 和 right 都不能偷
 *   dp[root][1] = root->val + dp[left][0] + dp[right][0]
 * base case：
 * dp[nullptr][0] = dp[nullptr][1] = 0
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
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    // 方法2，空间 o(1)，返回一个大小为 2 的数组，利用返回值即可
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* root)
    {
        // base case
        if (root == nullptr)
            return vector<int>{0, 0};
        // 递归子树，获得返回值
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // 状态转移，放在后序位置，这样可以利用到子树的返回值
        int dp_0 = max(left[0], left[1]) + max(right[0], right[1]);
        int dp_1 = root->val + left[0] + right[0];

        return vector<int>{dp_0, dp_1};
    }

    // 方法1，空间 o(n)，发现状态 root 只和两个子节点 left 和 right 有关
    // int rob(TreeNode* root) {
    //     dfs(root);
    //     return max(dp_0[root], dp_1[root]);
    // }

    // unordered_map<TreeNode *, int> dp_1;
    // unordered_map<TreeNode *, int> dp_0;
    // void dfs(TreeNode* root)
    // {
    //     // base case
    //     if (root == nullptr)
    //     {
    //         // 其实不用加等于0，因为 hash table 会自动创建不存在的 map[key]，并赋值 0
    //         dp_0[root] = 0;
    //         dp_1[root] = 0;
    //         return;
    //     }

    //     dfs(root->left);
    //     dfs(root->right);

    //     // 状态转移，放在后序位置，这样可以利用到子树的返回值
    //     dp_0[root] = max(dp_0[root->left], dp_1[root->left])
    //                 + max(dp_0[root->right], dp_1[root->right]);
    //     dp_1[root] = root->val + dp_0[root->left] + dp_0[root->right];            
    // }
};
// @lc code=end

