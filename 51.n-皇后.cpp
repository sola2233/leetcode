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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n == 0)
            return ans;
        
        vector<string> board(n, string(n, '.'));
        // 记录每一行放在哪一列
        vector<bool> column(n, false);
        // 记录方向一的斜线，从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
        vector<bool> ldiag(2*n-1, false);
        // 记录方向二的斜线，从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等
        vector<bool> rdiag(2*n-1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }

    /**
     * 辅函数，回溯法 
     * 路径：board 中小于 row 的那些行都已经成功放置了皇后
     * 选择列表：第 row 行的所有列都是放置皇后的选择
     * 结束条件：row 超过 board 的最后一行
     * @param ans 所有找到的棋盘矩阵
     * @param board 输入的 nxn 棋盘
     * @param column 记录的每一行放置的列位置
     * @param ldiag 方向一的斜线，从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
     * @param rdiag 方向二的斜线，从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等
     * @param row 当前遍历到的行
     * @param n 放置的皇后个数
     */
    void backtracking(vector<vector<string>> &ans, vector<string> &board, 
                        vector<bool> &column, vector<bool> &ldiag, 
                        vector<bool> &rdiag, int row, int n)
    {
        // 触发结束条件
        if (row == n)
        {
            ans.push_back(board);
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
            // 进入下一决策树，递归子节点
            backtracking(ans, board, column, ldiag, rdiag, row+1, n);
            // 撤销选择，回改当前节点状态
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }
};
// @lc code=end

