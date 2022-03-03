/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
/** 
 * 贪心
 * 局部最优：当前累加rest[j]的和curSum一旦小于0，起始位置至少要是j+1，因为从j开始一定不行。
 * 全局最优：找到可以跑一圈的起始位置。
 */
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_sum = 0; // 记录总剩余油量
        int cur_sum = 0; // 记录从 start 开始剩余油量
        int start = 0; // 出发的加油站位置，从 0 开始
        for (int i = 0; i < n; ++i)
        {
            int rest = gas[i] - cost[i];
            total_sum += rest;
            cur_sum += rest;
            if (cur_sum < 0) // 当前累加rest[i]和 curSum一旦小于0
            {
                start = i + 1; // 起始位置更新为i+1
                cur_sum = 0; // cur_sum从0开始
            }
        }

        return total_sum >= 0 ? start : -1;
    }
};
// @lc code=end

