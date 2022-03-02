/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
/** 
 * 回溯法
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board)
    {
        // 这里是一个二维递归，先要在 81 个格子里选择位置，每个位置又有 9 种选择
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                // 跳过已经有的数
                if (board[i][j] != '.')
                    continue;
                // 本层做选择
                for (char k = '1'; k <= '9'; ++k)
                {

                    // 跳过不合法的选择
                    if (!isValid(board, i, j, k))
                        continue;
                    board[i][j] = k;
                    // 如果找到合适一组立刻返回，不用回溯
                    if (backtracking(board))
                        return true;
                    board[i][j] = '.';
                }
                // 9个数都试完了，都不行，那么就返回false
                return false;
            }
        }
        // 遍历完没有返回false，说明找到了合适棋盘位置了
        return true;
    }

    // 可以继续优化，三个循环合并为一个循环
    bool isValid(vector<vector<char>>& board, int row, int col, char val)
    {
        // 检查行
        for (int j = 0; j < 9; ++j)
        {
            if (board[row][j] == val)
                return false;
        }
        // 检查列
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][col] == val)
                return false;
        }
        // 检查九宫格
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[start_row + i][start_col + j] == val)
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

