/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
/** 
 * moore 投票法
 * 因为多数数量大于 n / 2，可以认为一部分多数和所有剩下的数都抵消了
 * 最后剩下的就是多数
 */
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        // 遍历
        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
                candidate = nums[i];
            
            if (nums[i] == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};
// @lc code=end

