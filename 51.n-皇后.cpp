/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
/** 
 * 回溯法
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
        if (row == n)
        {
            ans.push_back(board);
            return;
        }
        // 对每一行遍历每一列位置
        for (int i = 0; i < n; ++i)
        {
            // 如果当前位置已访问、方向一斜线已被访问、方向二斜线已被访问，跳过
            if (column[i] || ldiag[n-row+i-1] || rdiag[row+i])
                continue;
            // 修改当前节点状态
            board[row][i] = 'Q';
            // 第 i 列修改为已访问，方向一斜线和方向二斜线修改为已访问
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;
            // 递归子节点，对每一行遍历
            backtracking(ans, board, column, ldiag, rdiag, row+1, n);
            // 回改当前节点状态
            board[row][i] = '.';
            column[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
        }
    }
};
// @lc code=end

