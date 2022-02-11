/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
/** 
 * 排序+双指针
 * 注意可能会溢出
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        // 负例
        if (n < 4) return res;
        // 排序
        sort(nums.begin(), nums.end());
        // 枚举 a
        for (int i = 0; i <= n - 4; ++i)
        {
            long a = nums[i]; // 防止溢出
            // 枚举 b
            for (int j = i + 1; j <= n-3; ++j)
            {
                long b = nums[j]; // 防止溢出
                // 双指针枚举 c 和 d
                int lo = j + 1, hi = n - 1;
                while (lo < hi)
                {
                    long c = nums[lo], d = nums[hi]; // 防止溢出
                    long sum = a + b + c + d; // 防止溢出
                    if (sum < target)
                    {
                        while (lo < hi && nums[lo] == c)
                            ++lo;
                    }
                    else if (sum > target)
                    {
                        while (lo < hi && nums[hi] == d)
                            --hi;
                    }
                    else if (sum == target)
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == c)
                            ++lo;
                        while (lo < hi && nums[hi] == d)
                            --hi;
                    }
                }
                // 去除重复的 b
                while (j <= n-3 && nums[j] == nums[j+1])
                    ++j;
            }
            // 去除重复的 a
            while (i <= n-4 && nums[i] == nums[i+1])
                ++i;
        }

        return res;
    }
};
// @lc code=end

