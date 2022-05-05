/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
/** 
 * 方法1，贪心
 * 要从覆盖范围出发，不管怎么跳，覆盖范围内一定是可以跳到的
 * 以最小的步数增加覆盖范围，覆盖范围一旦覆盖了终点，得到的就是最小步数
 * 
 * 方法2，贪心+双指针
 * 1.一个指针 left 在起跳位置，另一个指针 right 在跳跃范围内找能调到最远位置的跳跃位置
 * 2.找到后，left 更新为那个位置，跳跃数 step++，right 位置不变，重复 1
 */
#include <vector>
using namespace std;
class Solution {
public:

#if 0   
    // 方法2
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 负例
        if (n == 1)
            return 0;
        int cover = 0, step = 0;
        int left = 0, right = 0;
        while (right < n)
        {
            cover = left + nums[left];
            int max_cover = cover, next_left = 0;
            while (right <= cover && right < n)
            {
                if (right + nums[right] > max_cover)
                {
                    max_cover = max(max_cover, right + nums[right]);
                    next_left = right;
                }
                right++;
            }
            left = next_left;
            step++;
        }

        return step;
    }
#endif


#if 1   
    // 方法1，但是还可以继续优化，不需要检查是否到达终点
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 负例
        if (n == 1)
            return 0;
        int cur_dist = 0, max_dist = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            // 更新跳跃范围内下一次能到达的最远距离
            max_dist = max(max_dist, i + nums[i]);
            // 到达当前跳的最远距离
            if (i == cur_dist)
            {
                // 先检查当前最远距离是否是终点，不是终点才能继续跳
                if (cur_dist != n - 1)
                {
                    cur_dist = max_dist;
                    res++;
                }
                // 是终点直接退出
                else
                    break;
            }
        }

        return res;
    }
#endif
};
// @lc code=end

