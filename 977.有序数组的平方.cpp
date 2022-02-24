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
        int left = 0, right = nums.size() - 1;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            // 这里用临时变量，不能直接对数组元素操作，否则会对一个数多次平方
            int pow_right = nums[right] * nums[right];
            int pow_left = nums[left] * nums[left];
            // 大的数添加到 res 尾部
            if (pow_right > pow_left)
            {
                res[i] = pow_right;
                --right;
            }
            else
            {
                res[i] = pow_left;
                ++left;
            }
        }

        return res;
    }
};
// @lc code=end

