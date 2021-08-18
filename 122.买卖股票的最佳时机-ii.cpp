/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
/**
 * 贪心思想
 * 贪心算法的直觉：由于不限制交易次数，只要今天股价比昨天高，就交易。
 * 贪心算法只能用于计算最大利润，计算的过程并不是实际的交易过程。
 * 具体看题解
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        /** 最大利润 */
        int ret = 0;
        for(int i = 1; i < size; i++)
        {
            /** 今天价格比昨天高就交易 */
            ret += max(0, prices[i] - prices[i-1]);
        }
        return ret;
    }
};
// @lc code=end

