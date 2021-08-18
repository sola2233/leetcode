/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
/** 
 * 贪心算法
 * 只考虑相邻的两个数，如果出现非递减的情况，需要根据条件去修改nums[i-1]或nums[i]
 * 所以有两种修改方案
 * 1.缩小nums[i-1]
 * 2.放大nums[i]
 * 贪心策略:
 * 尽量不去修改nums[i]，因为可能会破坏后面的非递减序列，
 * 在不破坏前面子序列的情况下优先修改nums[i-1]
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        /** 从左往右遍历，看相邻两个数是否出现非递减情况 */
        for(int i = 1; i < size; i++)
        {
            if(nums[i-1] > nums[i])
            {
                /** 不破坏前面子序列的情况下修改nums[i-1] */
                if(i == 1 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                /** 无法修改nums[i-1]的情况下再修改nums[i] */
                else
                    nums[i] = nums[i-1];
                count++;
            }
        }
        return count > 1 ? false : true;
    }
};
// @lc code=end

