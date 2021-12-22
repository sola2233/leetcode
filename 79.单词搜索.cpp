/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        // 遍历矩阵中所有位置
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 对每个位置进行深度搜索
                backtracking(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }

    /**
     * 辅函数，回溯法，dfs
     * @param i 当前在矩阵中的位置
     * @param j 当前在矩阵中的位置
     * @param board 字符矩阵
     * @param word 需要寻找的字符串
     * @param find 是否找到字符串
     * @param visited 访问矩阵
     * @param pos 当前寻找字符在字符串word中的下标
     * @return 
     */
    void backtracking(int i, int j, vector<vector<char>> &board, 
    string &word, bool &find, vector<vector<bool>> &visited, int pos)
    {
        // 迭代终止条件
        // 判断搜索位置是否越界
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;
        // 当前位置已访问过、已经找到字符串、当前位置不等于要寻找的字符 直接返回
        if (visited[i][j] || find || board[i][j] != word[pos])
            return;
        // 如前面条件不满足，则当前位置就是找到要寻找的字符串最后一个字符，返回
        // 不修改当前节点状态是因为在前面修改就无法回溯了
        if (pos == word.size() - 1)
        {
            find = true;
            return;
        }
        // 修改当前节点状态
        visited[i][j] = true;
        // 递归子节点，四邻域
        backtracking(i + 1, j, board, word, find, visited, pos + 1);
        backtracking(i - 1, j, board, word, find, visited, pos + 1);
        backtracking(i, j + 1, board, word, find, visited, pos + 1);
        backtracking(i, j - 1, board, word, find, visited, pos + 1);
        // 回改当前节点状态
        visited[i][j] = false;
    }
};
// @lc code=end

