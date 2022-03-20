/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/** 
 * 双指针，头尾两个指针，大的放到新数组里
 * 类似于归并
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // 大的数添加到 res 尾部
            if (abs(nums[right]) > abs(nums[left]))
            {
                res[i] = nums[right] * nums[right];
                right--;
            }
            else
            {
                res[i] = nums[left] * nums[left];
                left++;
            }
        }

        return res;
    }

    // 这个麻烦一点
    // vector<int> sortedSquares(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> res;
    //     res.reserve(n);
    //     // left 指向最后一个负数，right 指向第一个正数
    //     int left = -1, right = 0;
    //     for (int i = 0; i < n; ++i)
    //     {
    //         if (nums[i] < 0)
    //         {
    //             left++;
    //             right++;
    //         }
    //         nums[i] *= nums[i];
    //     }

    //     while (left >= 0 && right < n)
    //     {
    //         if (nums[left] < nums[right])
    //             res.push_back(nums[left--]);
    //         else
    //             res.push_back(nums[right++]);
    //     }
    //     while (left >= 0)
    //         res.push_back(nums[left--]);
    //     while (right < n)
    //         res.push_back(nums[right++]);
    //     return res;
    // }
};
// @lc code=end

