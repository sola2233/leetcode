/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
/** 
 * dfs,bfs,并查集
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        // 上边和下边
        for (int j = 0; j < n; ++j)
        {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // 左边和右边
        for (int i = 0; i < m; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        // 遍历一遍 board
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size(), n = board[0].size();
        // 检查越界情况
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (board[i][j] != 'O')
            return;
        
        // 标记已访问
        board[i][j] = '#';
        // 递归访问相邻节点
        for (auto dir : dirs)
            dfs(board, i + dir[0], j + dir[1]);
    }
};
// @lc code=end

