/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

// @lc code=start
/** 
 * 一个节点的 分数 = 左子树节点个数 x 右子树节点个数 x 除自己外其他节点个数
 */
#include <vector>
#include <cstdint>
using namespace std;
class Solution {
public:
    // 记录每个节点的子节点
    vector<vector<int>> children;
    // 记录二叉树的总结点数
    int n;
    // 记录最高得分，要为 long，防止溢出
    long max_score;
    // 记录最高得分节点数目
    int res;
    int countHighestScoreNodes(vector<int>& parents) {
        // 初始化
        n = parents.size();
        children.resize(n);
        max_score = -1;
        res = 0;
        // 建图，从 1 开始，0 是根节点
        for (int i = 1; i < n; ++i)
        {
            int parent = parents[i];
            children[parent].push_back(i); // 添加 parent 的子节点
        }

        // 遍历，从根节点开始
        traverse(0);
        return res;
    }

    // dfs 遍历二叉树，返回以 root 为根的子树的节点数
    int traverse(int root)
    {
        long score = 1; // 记录当前节点的分数
        int sz = n - 1; // 记录与当前节点相连的父亲节点所连的一系列节点的数量
        for (auto& child : children[root])
        {
            // 递归计算子树大小
            int k = traverse(child);
            score *= k; // 计算得分
            sz -= k;
        }
        // 计算得分，不为 0 才能乘
        if (sz != 0)
            score *= sz;
        
        if (score > max_score)
        {
            max_score = score;
            res = 1;
        }
        else if (score == max_score)
            res++;

        return n - sz;
    }
};
// @lc code=end

