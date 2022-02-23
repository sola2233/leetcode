/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
/** 
 * 前缀和 + 二分搜索
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 前缀和数组
    vector<int> pre_sum;
    Solution(vector<int>& w) {
        // 初始化
        int n = w.size();
        // pre_sum 数组的索引比 w 偏了一位
        pre_sum.resize(n + 1);
        pre_sum[0] = 0;
        for (int i = 1; i < n + 1; ++i)
            pre_sum[i] = pre_sum[i-1] + w[i-1];
    }
    
    int pickIndex() {
        int n = pre_sum.size();
        // 随机选择一个数，位于 [1, pre_sum[n - 1]] 之间，取模范围会减一，所以这里要加一
        int target = rand() % pre_sum[n - 1] + 1;
        // 二分搜索找左边界
        int left = 0, right = n - 1;
        // 左闭右闭
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (pre_sum[mid] < target)
                left = mid + 1;
            else if (pre_sum[mid] > target)
                right = mid - 1;
            else if (pre_sum[mid] == target)
                right = mid - 1;
        }
        // pre_sum 的索引偏移了一位，还原为权重数组 w 的索引，返回下标需要减一
        return left - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

