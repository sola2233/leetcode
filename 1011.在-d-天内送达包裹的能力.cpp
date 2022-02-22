/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
/** 
 * 二分搜索
 * x: 载重能力，1 到 weights 的总和
 * f(x): 装货用的天数，单调降
 * target: days
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        // 左闭右闭
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 计算 f(x)
            int target = 1, cur = 0;
            for (int i = 0; i < weights.size(); ++i)
            {
                // 在每次超过载重时增加天数，所以 target 初始化为 1，不然会少一天
                if (weights[i] + cur > mid)
                {
                    ++target;
                    cur = 0;
                }
                cur += weights[i];
            }
            if (target < days)
                right = mid - 1;
            else if (target > days)
                left = mid + 1;
            else if (target == days)
                right = mid - 1; // 找下界，收缩右边界
        }

        return left;
    }
};
// @lc code=end

