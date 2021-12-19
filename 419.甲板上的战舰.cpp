/*
 * @lc app=leetcode.cn id=419 lang=cpp
 *
 * [419] 甲板上的战舰
 */

// @lc code=start
/** 
 * 深度优先搜索，但是似乎有更好的解法，以后再研究
 */
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> di{-1, 1,  0, 0};
    vector<int> dj{ 0, 0, -1, 1};
    /**
     * 主函数 
     */
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        // 遍历整个网格
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    dfs(board, i, j);
                    ++count;
                }
            }
        }

        return count;
    }

    /**
     * 辅函数，深度优先搜索 
     * @param board 待搜索网格
     * @param cur_i 目前位置 i
     * @param cur_j 当前位置 j
     */
    void dfs(vector<vector<char>> &board, int cur_i, int cur_j)
    {
        // 递归终止条件
        if (board[cur_i][cur_j] == '.')
            return;
        // 扫描过的位置赋值 '.'
        board[cur_i][cur_j] = '.';
        // 递归搜索四邻域
        int next_i, next_j;
        for (int i = 0; i < 4; ++i)
        {
            next_i = cur_i + di[i];
            next_j = cur_j + dj[i];
            // 越界检查
            if (next_i >=0 && next_i < board.size()
                && next_j >= 0 && next_j < board[0].size())
            {
                dfs(board, next_i, next_j);
            }
        }
    }
};
// @lc code=end

