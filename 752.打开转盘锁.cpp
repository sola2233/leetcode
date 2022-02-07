/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
/** 
 * BFS算法
 */
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 核心数据结构
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> deads(deadends.begin(), deadends.end());

        // 负例
        if (deads.count("0000"))
            return -1;

        // 向下扩散一层
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        while (!q.empty())
        {
            // 将当前队列中的所有节点向四周扩散
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                string cur = q.front();
                q.pop();
                // 结束条件
                if (cur == target)
                    return step;
                if (deads.count(cur)) // 如果在deadends中，跳过，相当于剪枝
                    continue;

                // 将 cur 的每个节点加入队列，4个字符，2个旋转方向，一共8个节点
                for (int j = 0; j < 4; ++j)
                {
                    // 跳过已访问的，防止走回头路
                    string up = num_prev(cur, j);
                    if (!visited.count(up))
                    {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = num_succ(cur, j);
                    if (!visited.count(down))
                    {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            // 递增层数
            ++step;
        }
        return -1;
    }

    // 将 cur 第 j 个字符向前转 1 位
    string num_prev(string cur, int j)
    {
        cur[j] = (cur[j] == '0' ? '9' : cur[j] - 1);
        return cur;
    }

    // 将 cur 第 j 个字符向后转 1 位
    string num_succ(string cur, int j)
    {
        cur[j] = (cur[j] == '9' ? '0' : cur[j] + 1);
        return cur;
    }
};
// @lc code=end

