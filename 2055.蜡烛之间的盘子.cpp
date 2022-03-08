/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

// @lc code=start
/** 
 * 方法1.模拟，用栈记录，会超时
 * 方法2.预处理 + 前缀和
 * https://leetcode-cn.com/problems/plates-between-candles/solution/zha-zhu-zhi-jian-de-pan-zi-by-leetcode-s-ejst/
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // 会超时的模拟
    // vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    //     string stk;
    //     vector<int> res;
    //     for (auto& query : queries)
    //     {
    //         stk.clear();
    //         int count = 0;
    //         for (int i = query[0]; i <= query[1]; ++i)
    //         {
    //             if (stk.empty() && s[i] == '|')
    //                 stk.push_back('|');
    //             else if (!stk.empty() && s[i] != '|')
    //                 stk.push_back(s[i]);
    //             else if (!stk.empty() && s[i] == '|')
    //             {
    //                 count += stk.size() - 1;
    //                 while (stk.size() > 1)
    //                     stk.pop_back();
    //             }
    //         }
    //         res.push_back(count);
    //     }
    //     return res;
    // }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        // 计算前缀和
        vector<int> pre_sum(n);
        for (int i = 0, sum = 0; i < n; i++)
        {
            if (s[i] == '*')
                sum++;
            pre_sum[i] = sum;
        }
        // 计算左侧第一个蜡烛位置
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|')
                l = i;
            left[i] = l;
        }
        // 计算右侧第一个蜡烛位置
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|')
                r = i;
            right[i] = r;
        }
        // 计算结果
        vector<int> res;
        for (auto& query : queries)
        {
            int l = right[query[0]];
            int r = left[query[1]];
            // 三种负例：左右没有蜡烛，或者给定区间内没有蜡烛，所以找到的左右蜡烛都越界了
            if (l == -1 || r == -1 || l >= r)
                res.push_back(0);
            else
                res.push_back(pre_sum[r] - pre_sum[l]);
        }
        return res;
    }
};
// @lc code=end

