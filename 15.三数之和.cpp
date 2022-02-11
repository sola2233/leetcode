/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
/** 
 * 排序+双指针
 * 3 = 1 + 2
 * 要找三个数 a b c，先枚举 a，b 和 c 通过 TwoSum 寻找
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        // 负例
        if (n < 3)
            return res;
        // 排序
        sort(nums.begin(), nums.end());
        
        // 枚举 a
        for (int i = 0; i <= n - 3; ++i)
        {
            int a = nums[i];
            // 枚举 b 和 c
            vector<vector<int>> two_res = TwoSum(nums, i + 1, -a);
            for (auto k : two_res)
            {
                k.push_back(a);
                res.push_back(k);
            }
            // 移动指针，去除重复元素
            while (i <= n - 3 && nums[i] == nums[i+1]) // 这里不用 a 来判断，for 循环本身还会递增一次
                ++i;
        }

        return res;
    }

    // 两数之和
    vector<vector<int>> TwoSum(vector<int>& nums, int start, int target)
    {
        // 双指针，这里 lo 初始化为 start
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi)
        {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target)
            {
                // 移动指针，去除重复元素
                while (lo < hi && nums[lo] == left)
                    ++lo;
            }
            else if (sum > target)
            {
                // 移动指针，去除重复元素
                while (lo < hi && nums[hi] == right)
                    --hi;
            }
            else if (sum == target)
            {
                res.push_back(vector<int>{left, right});
                // 移动指针，去除重复元素
                while (lo < hi && nums[lo] == left)
                    ++lo;
                while (lo < hi && nums[hi] == right)
                    --hi;
            }
        }

        return res;
    }
};
// @lc code=end

