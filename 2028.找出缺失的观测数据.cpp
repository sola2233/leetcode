/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
/** 
 * 模拟题
 */
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        // 缺失的数据和
        int missing_sum = mean * (n + m) - sum;
        // 负例
        if (missing_sum < n || missing_sum > 6 * n)
            return {};
        // 计算返回结果
        vector<int> res(n);
        int quot = missing_sum / n, remainder = missing_sum % n; // 均值和余数        
        for (int i = 0; i < n; ++i)
        {
            res[i] = quot + (i < remainder ? 1 : 0);
        }
        return res;
    }

};
// @lc code=end

