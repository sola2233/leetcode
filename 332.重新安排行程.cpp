/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
/** 
 * 回溯法，或者说图的 dfs 遍历
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
    // <出发地, <目的地, 剩余机票数>>，感觉像一个邻接表？？？
    // map 会排序，所以选择列表自动先选择字典序小的，如果 dfs 失败，再选择次小的
    unordered_map<string, map<string, int>> targets;
    vector<string> res; // 存放飞行路径
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 遍历映射
        for (auto& ticket : tickets)
        {
            string from = ticket[0], to = ticket[1];
            targets[from][to]++;
        }

        // 穷举
        res.push_back("JFK");
        backtracking(tickets.size());

        return res;
    }

    // 需要返回值，因为只需要找一条树枝，不用遍历整棵树
    bool backtracking(int ticket_num)
    {
        // 结束条件，机票用光了
        if (res.size() == ticket_num + 1)
            return true;

        // 在本层做选择
        string from = res.back();
        for (auto& target : targets[res.back()])
        {
            if (target.second == 0)
                continue;
            res.push_back(target.first);
            target.second--;
            // 需要加上判断，不然结果直接全部回溯掉了，失败了才会回溯
            if (backtracking(ticket_num))
                return true;
            res.pop_back();
            target.second++;
        }

        // 失败返回 false
        return false;
    }
};
// @lc code=end

