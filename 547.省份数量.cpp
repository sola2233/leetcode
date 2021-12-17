/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
/** 
 * 深度优先搜索，同695
 */
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 寻找省份数量，即图中连通域个数 
     */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // 城市个数
        int count = 0;              // 省份数量
        vector<bool> visited(n, false);
        // 遍历所有城市
        for (int i = 0; i < n; ++i)
        {
            // 搜索未访问的城市
            if (!visited[i])
            {
                // 搜索与他相邻的城市，标记为访问过
                dfs(isConnected, i, visited);
                // 每有一个连通分量，省份数量加一
                ++count;
            }
        }
        return count;
    }

    /**
     * 辅函数，深度优先搜索 
     * 递归访问某个城市所有的相邻城市
     * @param isConnected 图的邻接矩阵
     * @param i 当前城市
     * @param visited 记录每个城市是否被访问过
     * @return 
     */
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &visited)
    {
        // 标记当前城市为已访问
        visited[i] = true;
        // 遍历所有城市
        for (int k = 0; k < isConnected.size(); ++k)
        {
            // 如果某个城市与当前城市连接并且没有被访问过
            if (isConnected[i][k] == 1 && !visited[k])
                // 递归遍历这个城市
                dfs(isConnected, k, visited);
        }
    }
};
// @lc code=end

