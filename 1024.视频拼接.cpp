/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
/** 
 * 贪心
 * 有点像区间调度，需要先对区间排序，按 start 升序，start 相同再按 end 降序
 * 从第一个区间的 end 开始，遍历区间，在 [start, end] 内找能到达的最远位置
 * 这又有点像 45 跳跃游戏2 问题，或者说一模一样
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();
        // 排序
        sort(clips.begin(), clips.end(), [](auto& a, auto& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        // 遍历区间
        int cur_end = 0, next_end = 0;
        int i = 0, count = 0;
        while (i < n && clips[i][0] <= cur_end)
        {
            // 在当前 cur_end 范围内找到一个覆盖范围最远的下一个视频 next_end
            while (i < n && clips[i][0] <= cur_end)
            {
                next_end = max(next_end, clips[i][1]);
                ++i;
            }
            // 计数加 1，更新范围
            count++;
            cur_end = next_end;
            // 已经可以拼出视频就返回
            if (next_end >= time)
                return count;
        }

        return -1;        
    }
};
// @lc code=end

