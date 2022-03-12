/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
/** 
 * 双指针，做题不能只看模板，多做题才有模板，想到单调栈但是这题用不了
 */
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        // 遍历
        while (left < right)
        {
            int h = min(height[left], height[right]);
            res = max(res, h * (right - left));
            if (h == height[left])
                left++;
            else
                right--;
        }
        return res;
    }
};
// @lc code=end

