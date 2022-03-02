/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
/** 
 * 回溯法
 * 这个问题本质上跟全排列问题差不多，决策树的每一层表示棋盘上的每一行；
 * 每个节点可以做出的选择是，在该行的任意一列放置一个皇后。
 * 参考https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-by-leetcode-solution/
 * 算法步骤：
 * 使用一个数组记录每行放置的皇后的列下标，依次在每一行放置一个皇后。
 * 每次新放置的皇后都不能和已经放置的皇后之间有攻击：
 * 即新放置的皇后不能和任何一个已经放置的皇后在同一列以及同一条斜线上，
 * 并更新数组中的当前行的皇后列下标。
 * 当 N 个皇后都放置完毕，则找到一个可能的解。
 */
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> res; // 存放返回结果
    vector<string> board; // 存放一条树枝
    vector<vector<string>> solveNQueens(int n) {
        // 初始化
        board.resize(n, string(n, '.'));
        // // 记录每一行放在哪一列
        // vector<bool> column(n, false);
        // // 记录方向一的斜线，从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
        // vector<bool> ldiag(2 * n - 1, false);
        // // 记录方向二的斜线，从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等
        // vector<bool> rdiag(2 * n - 1, false);
        // backtracking1(column, ldiag, rdiag, 0, n);
        // 通俗一点的回溯法
        backtracking2(0, n);
        return res;
    }

    /**
     * 辅函数，回溯法 
     * 路径：board 中小于 row 的那些行都已经成功放置了皇后
     * 选择列表：第 row 行的所有列都是放置皇后的选择
     * 结束条件：row 超过 board 的最后一行
     * @param column 记录的每一行放置的列位置
     * @param ldiag 方向一的斜线，从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
     * @param rdiag 方向二的斜线，从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等
     * @param row 当前遍历到的行
     * @param n 放置的皇后个数
     */
    void backtracking1(vector<bool> &column, vector<bool> &ldiag, 
                        vector<bool> &rdiag, int row, int n)
    {
        // 触发结束条件
        if (row == n)
        {
            res.push_back(board);
            return;
        }
        // 遍历选择列表
        for (int i = 0; i < n; ++i)
        {
            // 排除不合法选择，这里用的方法比较巧妙，通常想不到这种巧妙方法可以暴力一点，遍历查看是否合法
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i])
                continue;
            // 做选择
            board[row][i] = 'Q';
            // 第 i 列修改为已访问，方向一斜线和方向二斜线修改为已访问
            // ldiag 中并不是 row-col，主要是为了让下标从 0 开始，且保证下标为正
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            // 进入下一层决策树，递归子节点
            backtracking1(column, ldiag, rdiag, row + 1, n);
            // 撤销选择，回改当前节点状态
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }

    /**
     * 回溯法 
     * @param row 当前递归层放的行
     */
    void backtracking2(int row, int n)
    {
        // 终止条件，放完最后下标为 n - 1 的行后，还会再递归一层，此时返回
        if (row == n)
        {
            res.push_back(board);
            return;
        }

        // 在本层做选择，即在一行内做选择，放在哪一列
        for (int col = 0; col < n; ++col)
        {
            // 跳过不符合的
            if (!isValid(row, col, n))
                continue;
            
            board[row][col] = 'Q';
            backtracking2(row + 1, n);
            board[row][col] = '.';
        }
    }

    // 检查摆放是否符合条件
    bool isValid(int row, int col, int n)
    {
        // 不用检查行，因为一行就放一个，不会冲突
        // 检查列
        for (int i = 0; i < row; ++i)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查 45 度
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查 135 度
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (board[i][j] == 'Q')
                return false;            
        }
        return true;
    }
};
// @lc code=end

