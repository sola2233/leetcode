/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 */

// @lc code=start
/** 
 * 递归子问题，看着好像回溯啊，同时可以加备忘录剪枝，消除重复计算
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
#include <unordered_map>
using namespace std;
class Solution {
public:
    // 做备忘录，剪枝加速用
    unordered_map<int, vector<TreeNode*>> hashmap;
    // 感觉像回溯了
    vector<TreeNode*> allPossibleFBT(int n) {
        // 下一层递归函数里的 res 与本层无关了，不用在意会记录子树的信息
        vector<TreeNode*> res;
        // 负例，偶数建不了满二叉树
        if (n % 2 == 0)
            return res;
        
        // base case
        if (n == 1)
        {
            res.push_back(new TreeNode(0));
            return res;
        }

        // 查询备忘录，做剪枝
        if (hashmap.count(n))
            return hashmap[n];
        
        // 本层做选择，root 占一个节点，要枚举左右子树占得节点个数情况
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode*> left_subtree = allPossibleFBT(i);
            vector<TreeNode*> right_subtree = allPossibleFBT(n - i - 1);
            // 左右子树的排列组合
            for (auto& left : left_subtree)
            {
                for (auto& right : right_subtree)
                {
                    TreeNode* root = new TreeNode(0, left, right);
                    res.push_back(root);
                }
            }
        }
        // 添加到备忘录
        hashmap[n] = res;
        return res;
    }
};
// @lc code=end

