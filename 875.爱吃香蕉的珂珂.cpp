/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
/** 
 * 二分搜索，从题目中抽象出x f(x) target
 * x: 吃香蕉速度，最小为 1，最大为 piles[i] 中最大的值，题目中为 10^9
 * f(x): 以速度 x 吃完香蕉的时间，单调降
 * target: 目标小时 H
 */
#include <vector>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1000000000;
        // 左闭右闭
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 计算 f(x)
            int target = 0;
            for (int& pile : piles)
            {
                target += pile / mid;
                if (pile % mid > 0)
                    ++target;
            }
            // 因为 f(x) 是单调降，所以条件对应的对 left 和 right 的行为也变了
            if (target < h)
                right = mid - 1;
            else if (target > h)
                left = mid + 1;
            else if (target == h)
                right = mid - 1; // 找下界，所以收缩右边界
        }

        return left;
    }
};
// @lc code=end

