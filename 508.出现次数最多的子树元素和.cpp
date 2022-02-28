/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

// @lc code=start
/** 
 * 递归子树，构建 hashmap 记录 sum 和相应的频次，同时记录最大频次
 * 遍历 hashmap，找最大频次对应的 sum 即可
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
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> res;
    unordered_map<int, int> hashmap;
    int max_count;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // 计算频率
        max_count = 0;
        getSum(root);
        // 遍历 hashmap
        for (auto ite = hashmap.begin(); ite != hashmap.end(); ite++)
        {
            if (ite->second == max_count)
                res.push_back(ite->first);
        }

        return res;
    }

    // 递归函数，返回以 root 为根的子树元素和
    int getSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        int left_sum = getSum(root->left);
        int right_sum = getSum(root->right);

        // 后序位置
        int sum = left_sum + right_sum + root->val;
        // 递增频率
        hashmap[sum]++;
        // 更新最大频率，便于主函数找到对应的数
        max_count = max(max_count, hashmap[sum]);

        return sum;
    }
};
// @lc code=end

