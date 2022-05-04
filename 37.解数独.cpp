/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
/** 
 * 回溯法
 * 方法1.二重循环，没有递归基，重点是函数返回值
 * 方法2.加上 start_idx 和递归基，函数返回值也是重点，速度比 1 快一点
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:

#if 0   // 方法1
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board)
    {
        // 这里是一个二重循环，先要在 81 个格子里选择位置，每个位置又有 9 种选择
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                // note 跳过已经有的数
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
                // note 9个数都试完了，都不行，那么就返回false
                return false;
            }
        }
        // note 遍历完没有返回false，说明找到了合适棋盘位置了
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
#endif

#if 1   // 方法2，速度比 1 快一点

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }

    bool backtracking(vector<vector<char>>& board, int start_idx)
    {
        // base case
        if (start_idx == 81)
            return true;

        int i = start_idx / 9;  // row
        int j = start_idx % 9;  // col

        // 跳过已有的数
        if (isdigit(board[i][j]))
            // note 这里这样写最好，直接返回 backtracking 的结果
            return backtracking(board, start_idx + 1);
            // note 这里要直接返回，不能用如下写法，因为一旦 backtracking 返回 fasle，
            // 程序就会往下执行，替换了原本的数字
            // if (backtracking(board, start_idx + 1))
            //     return true;
            // note 但是可以这样写，就是太啰嗦
            // if (backtracking(board, start_idx + 1))
            //     return true;
            // else
            //     return false;

        // 在选择列表做选择
        for (char k = '1'; k <= '9'; ++k)
        {
            // 跳过非法值
            if (!isValid(board, i, j, k))
                continue;
            // 递归 + 回溯
            board[i][j] = k;
            // note 这里利用返回值控制递归，一旦找到一个解，立马返回
            if (backtracking(board, start_idx + 1))
                return true;
            board[i][j] = '.';
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char val)
    {
        // 检查列
        for (int j = 0; j < 9; ++j)
        {
            if (board[row][j] == val)
                return false;
        }

        // 检查行
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][col] == val)
                return false;
        }

        // 检查九宫格
        int start_row = row / 3 * 3;
        int start_col = col / 3 * 3;
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
#endif
};
// @lc code=end

